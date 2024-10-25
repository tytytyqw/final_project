
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    inputQuery = new QTextEdit(this);
    inputQuery->setPlaceholderText("Введите поисковый запрос...");

    outputResults = new QTextEdit(this);
    outputResults->setReadOnly(true);
    searchButton = new QPushButton("Поиск", this);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(inputQuery);
    layout->addWidget(searchButton);
    layout->addWidget(outputResults);


    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    connect(searchButton, &QPushButton::clicked, this, &MainWindow::onSearchClicked);
}


void MainWindow::onSearchClicked() {
    QString query = inputQuery->toPlainText();
    std::string queryStr = query.toStdString();


    std::vector<std::string> results = searchEngine.searchQuery(queryStr);


    QString resultText;
    for (const auto& doc : results) {
        resultText += QString::fromStdString(doc) + "\n";
    }

    outputResults->setText(resultText);
}
