#include "Video.h"

Video::Video(QString ch, QWidget *parent) : QWidget(parent), chemin(ch){

    titre = new QLineEdit;
    titre->setText(ch);
    titre->setEnabled(false);
    vlay = new QVBoxLayout;
    hlay = new QHBoxLayout;
    videoPlayer = new QMediaPlayer;
    videoWidget = new QVideoWidget;

    sliderVolume = new QSlider(Qt::Horizontal);
    sliderVolume->setRange(0, 100);
    sliderVolume->setRange(0, 100);
    sliderVolume->setValue(50);
    sliderVolume->setFixedWidth(200);

    videoPlayer->setVolume(50);

    videoPlayer->setVideoOutput(videoWidget);
    videoPlayer->setMedia(QUrl::fromLocalFile(ch));

    play=new QPushButton("Lecture");
    play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    pause=new QPushButton("Pause");
    pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    stop=new QPushButton("Arrêt");
    stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    QObject::connect(play,SIGNAL(clicked()),videoPlayer,SLOT(play()));
    QObject::connect(pause,SIGNAL(clicked()),videoPlayer,SLOT(pause()));
    QObject::connect(stop,SIGNAL(clicked()),videoPlayer,SLOT(stop()));
    QObject::connect(sliderVolume, SIGNAL(valueChanged(int)), videoPlayer, SLOT(setVolume(int)));

    play->setFixedSize(70,20);
    pause->setFixedSize(70,20);
    stop->setFixedSize(70,20);
    //videoWidget->resize(900,500);

    vlay->addWidget(titre);
    vlay->addWidget(videoWidget);

    hlay->addWidget(play);
    hlay->addWidget(pause);
    hlay->addWidget(stop);
    vlay->addLayout(hlay);
    hlay->addWidget(sliderVolume);
    setLayout(vlay);
    videoPlayer->play();
}
