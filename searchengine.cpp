#include "searchengine.h"
#include <sstream>
#include <algorithm>

SearchEngine::SearchEngine() {
    indexDocument("document1.txt", "world news technology");
    indexDocument("document2.txt", "news world");
    indexDocument("document3.txt", "technology trends world");
}

void SearchEngine::indexDocument(const std::string& docName, const std::string& content) {
    std::istringstream stream(content);
    std::string word;

    while (stream >> word) {
        invertedIndex[word].push_back(docName);
    }
}

std::vector<std::string> SearchEngine::searchQuery(const std::string& query) {
    std::vector<std::string> result;
    std::unordered_map<std::string, int> docScore;
    std::istringstream stream(query);
    std::string word;

    while (stream >> word) {
        if (invertedIndex.find(word) != invertedIndex.end()) {
            for (const auto& doc : invertedIndex[word]) {
                docScore[doc]++;
            }
        }
    }

    std::vector<std::pair<int, std::string>> sortedDocs;
    for (const auto& pair : docScore) {
        sortedDocs.push_back({pair.second, pair.first});
    }

    std::sort(sortedDocs.rbegin(), sortedDocs.rend());

    for (const auto& pair : sortedDocs) {
        result.push_back(pair.second);
    }

    return result;
}
