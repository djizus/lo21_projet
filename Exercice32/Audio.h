#ifndef AUDIO_H
#define AUDIO_H

#include <QVideoWidget>
#include <QSlider>
#include <QStyle>
#include <QtGui>
#include <QMediaPlayer>
#include <QWidget>
#include <QAudio>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QString>
#include "notes.h"

class Audio : public QWidget {
    Q_OBJECT
    QMediaPlayer *audioPlayer;
    QVideoWidget *audioWidget;
    QVBoxLayout *vlay;
    QHBoxLayout *hlay;
    QPushButton *play;
    QPushButton *pause;
    QPushButton *stop;
    QLineEdit *titre;
    QSlider *sliderVolume;
    QString chemin;
public:
    explicit Audio(QString ch, QWidget *parent = 0);
};

#endif // AUDIO_H
