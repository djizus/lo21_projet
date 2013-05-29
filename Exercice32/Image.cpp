#include "Image.h"

Image::Image(QString ch, QWidget *parent) : QWidget(parent), chemin(ch){

    titre = new QLineEdit;
    vlay = new QVBoxLayout;
    hlay = new QHBoxLayout;

    pixmap_img = new QPixmap(chemin);
    label  = new QLabel;
    label->setPixmap(*pixmap_img);
    titre->setText(ch);
    titre->setEnabled(false);
    vlay->addWidget(titre);
    //spacing peut etre
    hlay->addWidget(label);
    vlay->addLayout(hlay);
    if(label->width()>700){
        label->setScaledContents(true);
    }
    setLayout(vlay);
}
