#include "map1.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QtMath>
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
       //顶部与底部初始化
       top[0][0].dopos(33,-198);
       top[0][1].dopos(97,-198);
       top[1][0].dopos(169,-198);
       top[1][1].dopos(743,-198);
       top[2][0].dopos(33,-99);
       top[2][1].dopos(607,-99);
       top[3][0].dopos(679,-99);
       top[3][1].dopos(743,-99);
       top[4][0].dopos(33,33);
       top[4][1].dopos(97,33);
       top[5][0].dopos(169,33);
       top[5][1].dopos(743,33);
       top[6][0].dopos(33,165);
       top[6][1].dopos(607,165);
       top[7][0].dopos(679,165);
       top[7][1].dopos(743,165);
       bottom[0][0].dopos(33,-155);
       bottom[0][1].dopos(607,-155);
       bottom[1][0].dopos(679,-155);
       bottom[1][1].dopos(743,-155);
       bottom[2][0].dopos(33,-23);
       bottom[2][1].dopos(97,-23);
       bottom[3][0].dopos(169,-23);
       bottom[3][1].dopos(743,-23);
       bottom[4][0].dopos(33,109);
       bottom[4][1].dopos(607,109);
       bottom[5][0].dopos(679,109);
       bottom[5][1].dopos(743,109);
       bottom[6][0].dopos(33,241);
       bottom[6][1].dopos(97,241);
       bottom[7][0].dopos(169,241);
       bottom[7][1].dopos(743,241);
       //人物设置
       kid1 = new kid(":/iwanna/kid3.png");
       kid1->setParent(this);
       kid1->setGeometry(kid1->x,kid1->y,kid1->width(),kid1->height());
       //人物移动
        QTimer *time = new QTimer(this);
        time->start(10);
        tempx=kid1->x;
        tempy=kid1->y;
       connect(time,&QTimer::timeout,[=](){
           if(this->canfall2(kid1->x,kid1->y)){
               qDebug()<<"fall";
               kid1->jumptimes=2;
               this->fall();
           }
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
    qDebug()<<QString("x=%1,y=%2,kidx=%3,kidy=%4").arg(event->x()).arg(event->y()-251).arg(kid1->x).arg(kid1->y);
}
//下落事件
bool map1::canfall(int x, int y){
    for(int i=0;i<8;i++)
        if(x>top[i][0].x&&x<top[i][1].x&&y==top[i][0].y)
            return true;
    if(tempy-y>=70)
        return true;
    return false;
}
bool map1::canfall2(int x, int y){
    for(int i=0;i<8;i+=2)
        if(x>bottom[i][1].x&&x<bottom[i+1][0].x&&y==bottom[i][1].y)
            return true;
    return false;
}
void map1::fall(){
    QTimer *time3 = new QTimer(this);//下落计时器
    time3->start(5);
    connect(time3,&QTimer::timeout,[=](){
        for(int i=0;i<8;i++)
            if(kid1->x>bottom[i][0].x&&kid1->x<bottom[i][1].x&&kid1->y==bottom[i][0].y){
                time3->stop();
                kid1->y-=1;
                kid1->jumptimes=0;//已经触底，重新激活跳跃事件
            }
        kid1->y+=1;
    });
}
//键盘事件
void map1::keyPressEvent(QKeyEvent *ev){
    Qbullet *bullet1;
    QTimer * time1;//射击计时器
    //跳跃计时器
    //跳跃
    if(ev->modifiers()==Qt::ControlModifier&&kid1->jumptimes<2){
        if(kid1->jumptimes==1)
            if(time2->isActive()){
            time2->stop();
            this->fall();
        }
        this->tempy=kid1->y;
        kid1->jumptimes+=1;
        time2 = new QTimer(this);
        time2->start(5);
        connect(time2,&QTimer::timeout,[=](){
            if(this->canfall(kid1->x,kid1->y)||kid1->jumptimes==0){
                time2->stop();
                if(kid1->jumptimes==1)
                    this->fall();
            }
            else{
                kid1->y-=kid1->jumptimes;
            }
        });
    }
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
        break;
        default:;
    }
 }
//人物不动时图片显示
bool map1::xischange(int x){
    if(x!=kid1->x)return true;
    return false;
}

