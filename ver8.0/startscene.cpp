#include "startscene.h"
#include"mypushbutton.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
startscene::startscene(QWidget *parent) : QMainWindow(parent)
{   //界面设置
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

    //开始场景
    QLabel *op2 = new QLabel(this);
    op2->setPixmap(QPixmap(":/iwanna/op2.png"));
    op2->setGeometry(0,14,this->width(),this->height());
    mypushbutton *startbtn = new mypushbutton(":/iwanna/startbutton.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.3+15,this->height()*0.6);
    //进入地图
    map01 = new map1;
    connect(startbtn,&mypushbutton::clicked,[=](){
        this->hide();
        map01->show();
    });
}
