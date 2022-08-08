#ifndef MAP1_H
#define MAP1_H
#include<QMouseEvent>
#include <QMainWindow>
#include"kid.h"
#include<QKeyEvent>
#include"Qbullet.h"
#include"barrier.h"
#include<QTimer>
#include"deadtool.h"
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
    void toolevent(int i);//道具事件触发
     bool ishit();//死亡事件触发
    kid *kid1;
    int tempx;//实现停止不动的图片
    int tempy;//跳跃高度实现
    barrier top[8][2];
    barrier bottom[8][2];
    QTimer *time2;//跳跃计时器
    deadtool *tool[3];//死亡道具
    deadtool *death;
    deadtool *word[3];
    bool istool[3];
    bool dead;
signals:

public slots:
};

#endif // MAP1_H
