#ifndef ARTICLEEDITEUR_H
#define ARTICLEEDITEUR_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <string>
#include "notes.h"

class ArticleEditeur : public QWidget {
    Q_OBJECT
    QLineEdit* titre;
    QTextEdit* text;
    QPushButton* save;
    QVBoxLayout* couche;
    Article* article;
public:
    explicit ArticleEditeur(Article* art, QWidget *parent = 0);
    Article& getArticle() { return *article; }
public slots:
    void saveArticle();
    void updateArticle();
private slots :
    void activerSave(QString str="");
};

#endif // ARTICLEEDITEUR_H
