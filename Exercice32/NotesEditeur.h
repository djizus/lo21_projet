#ifndef NOTESEDITEUR_H
#define NOTESEDITEUR_H

#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include "ArticleEditeur.h"

class NotesEditeur : public QMainWindow{
    Q_OBJECT
private:
    QTabWidget* onglets;
    ArticleEditeur* editeur;
    QLabel* visualisateurText;
public:
    void changementOnglet(int i);
    explicit NotesEditeur(QWidget *parent = 0);
signals:
public slots:
    void openArticle();
    void openImage();
    void openAudio();
    void openVideo();
    void openDocument();
};
#endif // NOTESEDITEUR_H
