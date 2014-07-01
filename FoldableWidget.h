#ifndef FOLDABLEWIDGET_H
#define FOLDABLEWIDGET_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>

class FoldableWidget : public QFrame{
    Q_OBJECT
    QWidget* foldableObj;
    QLabel* description;
    QPushButton* down;
    QPushButton* up;
    QHBoxLayout* haut;
    QVBoxLayout* bas;
    QVBoxLayout* fenetre;
public:
    explicit FoldableWidget(QWidget *f, QString d="", QWidget *parent = 0);
    void setDescription(QString d) { description->setText(d); }
    QWidget* getFoldableWidget() { return foldableObj; }
signals:
    void onOpen();
    void onClose();
public slots:
    void open();
    void close();
};

#endif // FOLDABLEWIDGET_H
