#ifndef MAP1_H
#define MAP1_H
#include<QMouseEvent>
#include <QMainWindow>
#include"kid.h"
#include<QKeyEvent>
#include"Qbullet.h"
#include"barrier.h"
#include<QTimer>
class map1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit map1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *ev);
    bool xischange(int x);
    bool canfall(int x,int y);//可以下落
    bool canfall2(int x,int y);
    void fall();//下落
    kid *kid1;
    int tempx;//实现停止不动的图片
    int tempy;//跳跃高度实现
    barrier top[8][2];
    barrier bottom[8][2];
    QTimer *time2;
signals:

public slots:
};

#endif // MAP1_H
