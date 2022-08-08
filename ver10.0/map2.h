#ifndef MAP2_H
#define MAP2_H
#include<QMouseEvent>
#include <QMainWindow>
#include"kid.h"
#include<QKeyEvent>
#include"Qbullet.h"
#include"barrier.h"
#include<QTimer>
#include"deadtool.h"
class map2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit map2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *ev);
    bool xischange(int x);
    bool canfall(int x,int y);//可以下落
    bool canfall2(int x,int y);
    void fall();//下落
    void toolevent(int i);//道具事件触发
    bool ishit();//死亡事件触发
    kid *kid1;
    int tempx;//实现停止不动的图片
    int tempy;//跳跃高度实现
    barrier top[2][2];
    barrier bottom[11][2];
    QTimer *time2;//跳跃计时器
    deadtool *tool[11];//死亡道具
    deadtool *death;
    bool istool[11];
    bool dead;
signals:
    void goback();
public slots:
};

#endif // MAP2_H
