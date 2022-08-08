#ifndef MAP1_H
#define MAP1_H
#include<QMouseEvent>
#include <QMainWindow>
#include"kid.h"
#include<QKeyEvent>
#include"Qbullet.h"
class map1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit map1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *ev);
    bool xischange(int x);
    kid *kid1;
    int tempx;
signals:

public slots:
};

#endif // MAP1_H
