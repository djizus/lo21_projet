#include "FoldableWidget.h"
#include <QIcon>

FoldableWidget::FoldableWidget(QWidget *f, QString d, QWidget *parent) :
        QFrame(parent),foldableObj(f){

    fenetre=new QVBoxLayout(this);
    description=new QLabel(d);
    down=new QPushButton;
    down->setIcon(QIcon("/icons/down.png"));
    down->setFixedWidth(20);
    haut=new QHBoxLayout;
    haut->addWidget(description);
    haut->addWidget(down);
    up=new QPushButton;
    up->setIcon(QIcon("/icons/up.png"));
    fenetre->addLayout(haut);
    fenetre->addWidget(foldableObj);
    fenetre->addWidget(up);
    foldableObj->hide();
    up->hide();
    QObject::connect(down,SIGNAL(clicked()),this,SLOT(open()));
    QObject::connect(up,SIGNAL(clicked()),this,SLOT(close()));
}

void FoldableWidget::open(){
    description->hide();
    down->hide();
    foldableObj->show();
    up->show();
    adjustSize();
    emit onOpen();
}

void FoldableWidget::close(){
    foldableObj->hide();
    up->hide();
    description->show();
    down->show();
    adjustSize();
    emit onClose();
}
