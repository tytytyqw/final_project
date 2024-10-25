#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include "searchengine.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onSearchClicked();

private:
    QTextEdit *inputQuery;
    QTextEdit *outputResults;
    QPushButton *searchButton;
    SearchEngine searchEngine;
};

#endif
