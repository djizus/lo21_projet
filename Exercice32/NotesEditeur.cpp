#include "NotesEditeur.h"
#include "notes.h"
#include "Audio.h"
#include "Image.h"
#include "Video.h"
#include <QMenuBar>
#include <QStyle>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QToolBar>
//
NotesEditeur::NotesEditeur(QWidget *parent):QMainWindow(parent){
    setWindowTitle("Editeur de notes");
    setMinimumSize(900,700);
    QMenu *mFichier = menuBar()->addMenu("&Fichier");
    QMenu *mEdition = menuBar()->addMenu("&Edition");
    QMenu *mNouveau = mFichier->addMenu("&Ouvrir");
    QAction * actionNewArticle=mNouveau->addAction("Article");
    QAction * actionNewImage=mNouveau->addAction("Image");
    QAction * actionNewAudio=mNouveau->addAction("Enregistrement Audio");
    QAction * actionNewVideo=mNouveau->addAction("Enregistrement Video");
    QAction * actionNewDocument=mNouveau->addAction("Document");
    mFichier->addSeparator();
    QAction *actionQuitter = mFichier->addAction("&Quitter");
    actionQuitter->setIcon(QIcon("../Exercice32/icons/quitter.png"));
    actionNewArticle->setIcon(QIcon("../Exercice32/icons/article.png"));
    actionNewImage->setIcon(QIcon("../Exercice32/icons/image.png"));
    actionNewAudio->setIcon(QIcon("../Exercice32/icons/audio.png"));
    actionNewVideo->setIcon(QIcon("../Exercice32/icons/video.png"));
    actionNewDocument->setIcon(QIcon("../Exercice32/icons/document.png"));
    QToolBar *toolBarOpen = addToolBar("Open");
    toolBarOpen->addAction(actionNewArticle);
    toolBarOpen->addAction(actionNewImage);
    toolBarOpen->addAction(actionNewAudio);
    toolBarOpen->addAction(actionNewVideo);
    toolBarOpen->addAction(actionNewDocument);

    // connections
    connect(actionNewArticle, SIGNAL(triggered()),this,SLOT(openArticle()));
    connect(actionNewImage, SIGNAL(triggered()),this,SLOT(openImage()));
    connect(actionNewAudio, SIGNAL(triggered()),this,SLOT(openAudio()));
    connect(actionNewVideo, SIGNAL(triggered()),this,SLOT(openVideo()));
    connect(actionNewDocument, SIGNAL(triggered()),this,SLOT(openDocument()));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void NotesEditeur::openImage(){
    QString chemin = QFileDialog::getOpenFileName(this, tr("Afficher une image"), "", tr(" Images (*.png *.jpg *.bmp)"));
    if (chemin!=""){
        Image* img=new Image(chemin);
        setCentralWidget(img);
    }
}

void NotesEditeur::openAudio(){
    QString chemin = QFileDialog::getOpenFileName(this, tr("Ouvir un fichier audio"), "", tr(" Sons (*.mp3 *.wav)"));
    if (chemin!=""){
        Audio* son=new Audio(chemin);
        setCentralWidget(son);
    }
}

void NotesEditeur::openVideo(){
    QString chemin = QFileDialog::getOpenFileName(this, tr("Lire une video"), "", tr(" Videos (*.mp4 *.mpeg *.mpg)"));
    if (chemin!=""){
        Video* vid=new Video(chemin);
        setCentralWidget(vid);
    }
}

void NotesEditeur::openDocument(){
    QMessageBox::warning(this, "Avertissement", "Cette fonctionnalite n’a pas encore ete implementee...");
}

void NotesEditeur::openArticle(){
    QString chemin = QFileDialog::getOpenFileName(this, tr("Ouvir un article"), "", tr(" Texte (*.not *.txt)"));
    if (chemin!=""){
        Article& art=NotesManager::getInstance().getArticle(chemin);
        ArticleEditeur* fenetre=new ArticleEditeur(&art);
        setCentralWidget(fenetre);
    }
}

void NotesEditeur::changementOnglet(int i){
    if (i==1){
        editeur->updateArticle();
        QString str=editeur->getArticle().getTitle()+"\n\n"+editeur->getArticle().
                    getText()+"\n";
        visualisateurText->setText(str);
    }
}
