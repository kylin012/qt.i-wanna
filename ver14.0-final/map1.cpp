#include "map1.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QtMath>
#include<QApplication>
map1::map1(QWidget *parent) : QMainWindow(parent)
{
    //界面设置
       QApplication *app;
       dead=false;
       map02 = new map2;
       setFixedSize(799,620);
       setWindowIcon(QIcon(":/iwanna/icon.png"));
       setWindowTitle("I wanna be the guyyyyyyyy");
       sound1 = new QSound(":/iwanna/san.wav",this);
       sound1->setLoops(-1);
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
       //背景元素设置
       word[0]=new deadtool(":/iwanna/word1.png");
       word[1]=new deadtool(":/iwanna/word2.png");
       word[2]=new deadtool(":/iwanna/word3.png");
       for(int i=0;i<3;i++)
           word[i]->setParent(this);
       word[0]->setGeometry(200,-60,word[0]->width(),word[0]->height());
       word[1]->setGeometry(400,72,word[1]->width(),word[1]->height());
       word[1]->hide();
        word[2]->setGeometry(300,204,word[2]->width(),word[2]->height());
        word[2]->hide();
       //人物设置
       kid1 = new kid(":/iwanna/kid3.png");
       kid1->setParent(this);
       kid1->setGeometry(kid1->x,kid1->y,kid1->width(),kid1->height());
       //死亡道具设置
       for(int i=0;i<3;i++){
           tool[i] =new deadtool(":/iwanna/juchi.png");
           tool[i]->setParent(this);
           tool[i]->setGeometry(-80,-60+i*132,tool[i]->width(),tool[i]->height());
           tool[i]->x=-80;
           tool[i]->y=-60+i*132;
           istool[i]=false;
       }
       tool[1]->setGeometry(800,72,tool[1]->width(),tool[1]->height());
       tool[1]->x=800;tool[1]->y=72;
       //监听下一场景的返回
       connect(map02,&map2::goback,[=](){
            map02->hide();
            this->show();
       });
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
       //人物移动、道具触发检测、死亡
       death = new deadtool(":/iwanna/death1.png");
       death->setParent(this);
        death->setGeometry(220,50,death->width(),death->height());
        death->hide();
        QTimer *time = new QTimer(this);
        time->start(10);
        tempx=kid1->x;
        tempy=kid1->y;
       connect(time,&QTimer::timeout,[=](){
           //道具触发
           if(kid1->y==tool[0]->y+37&&istool[0]==false){
               istool[0]=true;
               QTimer::singleShot(500,this,[=](){
                   this->toolevent(0);
               });}
           if(kid1->y==tool[1]->y+37&&istool[1]==false){
               istool[1]=true;
               QTimer::singleShot(500,this,[=](){
                   this->toolevent(1);
               });}
           if(kid1->y==tool[2]->y+37&&istool[2]==false){
               istool[2]=true;
               QTimer::singleShot(500,this,[=](){
                   this->toolevent(2);
               });}
           //是否死亡
           if(this->ishit()){
               death->show();
               if(dead==false)map02->deadtimes++;
               dead=true;
           }
           //下落
           if(this->canfall2(kid1->x,kid1->y)){
               kid1->jumptimes=2;
               this->fall();
           }
           //移动
           if(!xischange(tempx)){
               if(kid1->pos>2)kid1->pos=3;
               else kid1->pos=1;
           }
           tempx = kid1->x;
           kid1->move(kid1->x,kid1->y);
           kid1->imgchange();
           //进入下一地图
           if(kid1->x>97&&kid1->x<169&&kid1->y<-280){
               this->hide();
               sound1->stop();
               map02->show();
               map02->sound2->play();
               map02->kid1->move(47,339);
               map02->kid1->x=47;
               map02->kid1->y=339;
           }
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
//void map1::mousePressEvent(QMouseEvent *event){
//    qDebug()<<QString("x=%1,y=%2,kidx=%3,kidy=%4").arg(event->x()).arg(event->y()-251).arg(kid1->x).arg(kid1->y);
//}
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
//道具事件
void map1::toolevent(int i){
    QTimer *time3;
    time3 = new QTimer(this);
    time3->start(5);
    connect(time3,&QTimer::timeout,[=](){
        if(i==0){
            tool[i]->x+=5;
            tool[i]->move(tool[i]->x,tool[i]->y);
            if(tool[i]->x>630){
                time3->stop();
                tool[i]->x=900;
                tool[i]->move(900,tool[i]->y);}
        }
        else if(i==1){
            tool[i]->x-=5;
            tool[i]->move(tool[i]->x,tool[i]->y);
            if(tool[i]->x<30){
                time3->stop();
                tool[i]->x=900;
                tool[i]->move(900,tool[i]->y);
            }
        }
        else{
            tool[i]->x+=5;
            tool[i]->move(tool[i]->x,tool[i]->y);
            if(tool[i]->x>750){
                time3->stop();
                tool[i]->x=900;
                tool[i]->move(900,tool[i]->y);}
        }
    });
}
//死亡事件
bool map1::ishit(){
    for(int i=0;i<3;i++){
        if(kid1->y-(tool[i]->y+37)>=-90&kid1->y-(tool[i]->y+37)<=0&&abs(kid1->x-tool[i]->x-70)<=5)
            return true;
    }
    if(kid1->y>350)
        return true;
    return false;
}
//键盘事件
void map1::keyPressEvent(QKeyEvent *ev){
    Qbullet *bullet1;
    QTimer * time1;//射击计时器
    //跳跃
    if(ev->modifiers()==Qt::ControlModifier&&kid1->jumptimes<2){
        if(dead)return;
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
        if(dead)return;
        if(kid1->x>35)kid1->x-=5;
        if(kid1->pos!=1)kid1->pos=1;
        else kid1->pos=2;
        break;
    case Qt::Key_Right:
        if(dead)return;
        if(kid1->x<745)kid1->x+=5;
        if(kid1->pos!=3)kid1->pos=3;
        else kid1->pos=4;
        break;
        //子弹发射
    case Qt::Key_Z:
        if(dead)return;
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
            if(bullet1->y>=-105&&bullet1->y<=-25&&bullet1->x<=325&&bullet1->x>=315){
                word[0]->hide();
                word[1]->show();
            }
            else if(bullet1->y>=32&&bullet1->y<=96&&bullet1->x<=515&&bullet1->x>=505){
                    word[1]->hide();
                    word[2]->show();
                }
            else if(bullet1->y>=160&&bullet1->y<=225&&bullet1->x<=422&&bullet1->x>=412){
                    word[2]->hide();
                }
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
    case Qt::Key_R://刷新
    {   if((tool[0]->x==-80||tool[0]->x==900)&&(tool[1]->x==800||tool[1]->x==900)&&(tool[2]->x==-80||tool[2]->x==900)){
        death->hide();
        word[0]->show();
        word[1]->hide();
        word[2]->hide();
        kid1->move(133,-155);
        kid1->x=133;
        kid1->y=-155;
        kid1->pos=3;
        kid1->jumptimes=0;
        tempx=kid1->x;
        tempy=kid1->y;
        for(int i=0;i<3;i++){
            istool[i]=false;
            tool[i]->move(-80,-60+i*132);
            tool[i]->x=-80;
            tool[i]->y=-60+i*132;
        }
        tool[1]->move(800,72);
        tool[1]->x=800;tool[1]->y=72;
        dead=false;
        break;
    }}
    default:;
    }
 }
//人物不动时图片显示
bool map1::xischange(int x){
    if(x!=kid1->x)return true;
    return false;
}

