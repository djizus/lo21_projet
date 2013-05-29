#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include "notes.h"

class Image : public QWidget {
    Q_OBJECT
    QLineEdit *titre;
    QPixmap *pixmap_img;
    QLabel  *label;
    QVBoxLayout *vlay;
    QHBoxLayout *hlay;
    QString chemin;
public:
    explicit Image(QString ch, QWidget *parent = 0);
};

#endif // IMAGE_H
