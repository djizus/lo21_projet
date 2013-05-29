#include "ArticleEditeur.h"
//
ArticleEditeur::ArticleEditeur(Article* art, QWidget *parent) : QWidget(parent),article(art){
    titre = new QLineEdit(this);
    text= new QTextEdit(this);
    save= new QPushButton("Sauver", this);
    couche = new QVBoxLayout;
    couche->addWidget(titre);
    couche->addWidget(text);
    couche->addWidget(save);
    titre->setText(article->getTitle());
    text->setText(article->getText());
    QObject::connect(titre,SIGNAL(textEdited(QString)),this,SLOT(activerSave(QString)));
    QObject::connect(titre,SIGNAL(textChanged()),this,SLOT(activerSave()));
    setLayout(couche);
}

void ArticleEditeur::updateArticle(){
    article->setTitle(titre->text());
    article->setText(text->toPlainText());
}
void ArticleEditeur::saveArticle(){
    updateArticle();
    NotesManager::getInstance().saveArticle(*article);
    QMessageBox::information(this, "Sauvegarde", "Votre article a bien ete sauvegarde !");
    save->setEnabled(false);
}

void ArticleEditeur::activerSave(QString)
{
    save->setEnabled(true);
}
