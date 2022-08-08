#include "startscene.h"
#include"mypushbutton.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
#include<QSound>
#include<QApplication>
startscene::startscene(QWidget *parent) : QMainWindow(parent)
{   //界面设置
    setFixedSize(799,620);
    setWindowIcon(QIcon(":/iwanna/icon.png"));
    setWindowTitle("I wanna be the guyyyyyyyy");
    QApplication *app;
    //菜单设置
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startmenu = bar->addMenu("开始");
    QMenu *helpmenu = bar->addMenu("帮助");
    QAction *quitaction = startmenu->addAction("退出");
    QAction *helpaction = helpmenu->addAction("帮助");
    QAction *bgaction = helpmenu->addAction("游戏背景");
    connect(quitaction,&QAction::triggered,[=](){
        if(QMessageBox::Yes==QMessageBox::warning(this,"警告","确认退出？",QMessageBox::Yes|QMessageBox::No))
            app->quit();
    });
    connect(helpaction,&QAction::triggered,[=](){
        QMessageBox::about(this,"操作指南","按←和→键进行左右移动<br>按Z键进行射击<br>按Ctrl键进行跳跃<br>按R键重生<br>注意：本项目暂不支持同时响应两个按键<br>如出现其他bug，请善用R键与退出键");
    });
    connect(bgaction,&QAction::triggered,[=](){
        QMessageBox::about(this,"游戏背景","一位年轻的kid一直憧憬着成为大人，这次他下定决心，带着枪离开了家，寻找快速成为大人的方法，他能成功吗？<br>这也许，会是个有些黑暗与荒谬的物语······<br><br>本项目中包含的游戏元素：<br>"
                                       " 主体：i wanna be the guy<br>"
                                       " 台词：王者荣耀、游戏王、三国杀、巫师3<br>"
                                       " 图片：元气骑士、小小梦魇、马里奥、只狼、疯狂小人战斗<br>"
                                       " 音乐：穿越火线、gta、地下城与勇士、寂静岭2");
    });

    //开始场景
    QLabel *op2 = new QLabel(this);
    op2->setPixmap(QPixmap(":/iwanna/op2.png"));
    op2->setGeometry(0,14,this->width(),this->height());
    mypushbutton *startbtn = new mypushbutton(":/iwanna/startbutton.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.3+15,this->height()*0.6);
    QSound *startsound = new QSound(":/iwanna/crossfire.wav",this);
    startsound->setLoops(-1);
    startsound->play();
    //进入地图
    map01 = new map1;
    connect(startbtn,&mypushbutton::clicked,[=](){
        startbtn->zoom1();
        startbtn->zoom2();
        QTimer::singleShot(500,this,[=](){
            startsound->stop();
            map01->sound1->play();
            this->hide();
            map01->show();
        });
    });
}
