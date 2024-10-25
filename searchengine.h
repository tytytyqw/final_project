#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <unordered_map>
#include <vector>
#include <string>

class SearchEngine {
public:
    SearchEngine();
    std::vector<std::string> searchQuery(const std::string& query);

private:
    std::unordered_map<std::string, std::vector<std::string>> invertedIndex;
    void indexDocuments();
    void indexDocument(const std::string& docName, const std::string& content);
};

#endif
