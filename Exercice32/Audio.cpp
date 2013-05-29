#include "Audio.h"

Audio::Audio(QString ch, QWidget *parent) : QWidget(parent), chemin(ch){

    audioWidget = new QVideoWidget;

    audioPlayer = new QMediaPlayer(this);
    hlay=new QHBoxLayout();
    vlay=new QVBoxLayout();
    play=new QPushButton("Lecture");
    play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    pause=new QPushButton("Pause");
    pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    stop=new QPushButton("Arrêt");
    stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    //ui->progressBar->setRange(0,100);
    titre = new QLineEdit;
    titre->setText(ch);
    titre->setEnabled(false);

    sliderVolume = new QSlider(Qt::Vertical);
    sliderVolume->setRange(0, 100);
    sliderVolume->setRange(0, 100);
    sliderVolume->setValue(50);
    sliderVolume->setFixedHeight(80);

    audioPlayer->setVolume(50);
    audioPlayer->setVideoOutput(audioWidget);
    audioPlayer->setMedia(QUrl::fromLocalFile(ch));

    QObject::connect(play,SIGNAL(clicked()),audioPlayer,SLOT(play()));
    QObject::connect(pause,SIGNAL(clicked()),audioPlayer,SLOT(pause()));
    QObject::connect(stop,SIGNAL(clicked()),audioPlayer,SLOT(stop()));
    QObject::connect(sliderVolume, SIGNAL(valueChanged(int)), audioPlayer, SLOT(setVolume(int)));

    vlay->addWidget(titre);
    vlay->addWidget(sliderVolume);
    hlay->addWidget(play);
    hlay->addWidget(pause);
    hlay->addWidget(stop);
    vlay->addLayout(hlay);
    vlay->addWidget(audioWidget);

    setLayout(vlay);

    audioPlayer->play();
}
