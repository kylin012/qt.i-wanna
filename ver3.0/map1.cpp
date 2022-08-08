#include "map1.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
#include<QPainter>
#include<QDebug>
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
       kid *kid1 = new kid(":/iwanna/kid1.png");
       kid1->setParent(this);
       kid1->setGeometry(133,-155,kid1->width(),kid1->height());
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
