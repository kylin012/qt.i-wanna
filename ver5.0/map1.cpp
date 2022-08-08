#include "map1.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<QTimer>
map1::map1(QWidget *parent) : QMainWindow(parent)
{
    //界面设置
       setFixedSize(799,620);
       setWindowIcon(QIcon(":/iwanna/icon.png"));
       setWindowTitle("I wanna be the guyyyyyyyy");
       //菜单设置
       QMenuBar *bar = menuBar();
       setMenuBar(bar);
       QMenu *startmenu = bar->addMenu("开始");
       QMenu *helpmenu = bar->addMenu("帮助");
       QAction *quitaction = startmenu->addAction("退出");
       QAction *helpaction = helpmenu->addAction("帮助");
       connect(quitaction,&QAction::triggered,[=](){
           if(QMessageBox::Yes==QMessageBox::warning(this,"警告","确认退出？",QMessageBox::Yes|QMessageBox::No))
               this->close();

       });
       connect(helpaction,&QAction::triggered,[=](){
           QMessageBox::about(this,"操作指南","");
       });
       //人物设置
       kid1 = new kid(":/iwanna/kid3.png");
       kid1->setParent(this);
       kid1->setGeometry(kid1->x,kid1->y,kid1->width(),kid1->height());
       //人物移动
        QTimer *time = new QTimer(this);
        time->start(10);
        tempx=kid1->x;
       connect(time,&QTimer::timeout,[=](){
           if(!xischange(tempx)){
               if(kid1->pos>2)kid1->pos=3;
               else kid1->pos=1;
           }
           tempx = kid1->x;
           kid1->move(kid1->x,kid1->y);
           kid1->imgchange();
       });
}
//地图加载
void map1::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/iwanna/map1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
//找坐标
void map1::mousePressEvent(QMouseEvent *event){
    qDebug()<<QString("x=%1,y=%2").arg(event->x()).arg(event->y());
}
//键盘事件
void map1::keyPressEvent(QKeyEvent *ev){
    Qbullet *bullet1;
    QTimer * time1;
    switch (ev->key()){
        case Qt::Key_Left:
            if(kid1->x>35)kid1->x-=5;
            if(kid1->pos!=1)kid1->pos=1;
            else kid1->pos=2;
        break;
        case Qt::Key_Right:
            if(kid1->x<745)kid1->x+=5;
            if(kid1->pos!=3)kid1->pos=3;
            else kid1->pos=4;
        break;
        //子弹发射
        case Qt::Key_Z:
        bullet1 = new Qbullet(":/iwanna/bullet.png");
        bullet1->setParent(this);
        if(kid1->pos<3)
            bullet1->x=kid1->x-10;
        else
            bullet1->x=kid1->x+20;
        bullet1->y=kid1->y;
        bullet1->pos= kid1->pos;
        bullet1->setGeometry(bullet1->x,bullet1->y,bullet1->width(),bullet1->height());
        bullet1->show();
        time1 = new QTimer(this);
        time1->start(20);
        connect(time1,&QTimer::timeout,[=](){
            if(bullet1->pos>2)
            bullet1->x+=10;
            else
            bullet1->x-=10;
            bullet1->move(bullet1->x,bullet1->y);
            if(bullet1->x>800|bullet1->x<-30){
                time1->stop();
                delete bullet1;
            }
        });
\
        break;
        default:;
    }
 }
//人物不动时图片显示
bool map1::xischange(int x){
    if(x!=kid1->x)return true;
    return false;
}

