#ifndef VIDEO_H
#define VIDEO_H

#include <QStyle>
#include <QtGui>
#include <QMediaPlayer>
#include <QWidget>
#include <QSlider>
#include <QApplication>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QString>
#include <QLineEdit>
#include "notes.h"

class Video : public QWidget {
    Q_OBJECT
    QMediaPlayer *videoPlayer;
    QVBoxLayout *vlay;
    QHBoxLayout *hlay;
    QVideoWidget* videoWidget;
    QString chemin;
    QPushButton *play;
    QPushButton *pause;
    QPushButton *stop;
    QLineEdit *titre;
    QSlider *sliderVolume;

public:
    explicit Video(QString ch, QWidget *parent = 0);
};

#endif // VIDEO_H
