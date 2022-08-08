#include "map2.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QtMath>
map2::map2(QWidget *parent) : QMainWindow(parent)
{
    //界面设置
       dead=false;
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
       kid1->x=47;kid1->y=339;
       kid1->setGeometry(kid1->x,kid1->y,kid1->width(),kid1->height());
       //顶部与底部初始化
       top[0][0].dopos(707,197);
       top[0][1].dopos(766,197);
       top[1][0].dopos(616,164);
       top[1][1].dopos(679,164);
       bottom[0][0].dopos(33,339);
       bottom[0][1].dopos(97,339);
       bottom[1][0].dopos(169,339);
       bottom[1][1].dopos(649,339);
       bottom[2][0].dopos(649,306);
       bottom[2][1].dopos(682,306);
       bottom[3][0].dopos(679,273);
       bottom[3][1].dopos(743,273);
       bottom[4][0].dopos(-5,75);
       bottom[4][1].dopos(33,75);
       bottom[5][0].dopos(33,141);
       bottom[5][1].dopos(129,141);
       bottom[6][0].dopos(265,75);
       bottom[6][1].dopos(352,75);
       bottom[7][0].dopos(361,75);
       bottom[7][1].dopos(414,75);
       bottom[8][0].dopos(520,75);
       bottom[8][1].dopos(607,75);
       bottom[9][0].dopos(616,108);
       bottom[9][1].dopos(702,108);
       bottom[10][0].dopos(711,141);
       bottom[10][1].dopos(743,141);
       //死亡道具设置
       for(int i=0;i<11;i++){
           tool[i] =new deadtool(":/iwanna/apple.png");
           tool[i]->setParent(this);
           istool[i]=false;
       }
       //前七个向下落
       tool[0]->setGeometry(94,229,tool[0]->width(),tool[0]->height());
       tool[0]->x=94;tool[0]->y=229;
       tool[1]->setGeometry(262,252,tool[0]->width(),tool[0]->height());
       tool[1]->x=262,tool[1]->y=252;
       tool[2]->setGeometry(345,230,tool[0]->width(),tool[0]->height());
       tool[2]->x=345,tool[2]->y=230;
       tool[3]->setGeometry(369,235,tool[0]->width(),tool[0]->height());
       tool[3]->x=369,tool[3]->y=235;
       tool[4]->setGeometry(440,250,tool[0]->width(),tool[0]->height());
       tool[4]->x=440,tool[4]->y=250;
       tool[5]->setGeometry(485,238,tool[0]->width(),tool[0]->height());
       tool[5]->x=485,tool[5]->y=238;
       tool[6]->setGeometry(672,215,tool[0]->width(),tool[0]->height());
       tool[6]->x=672,tool[6]->y=215;
       //后四个向上
       tool[7]->setGeometry(308,206,tool[0]->width(),tool[0]->height());
       tool[7]->x=308,tool[7]->y=206;
       tool[8]->setGeometry(502,229,tool[0]->width(),tool[0]->height());
       tool[8]->x=502,tool[8]->y=229;
       tool[9]->setGeometry(607,230,tool[0]->width(),tool[0]->height());
       tool[9]->x=607,tool[9]->y=230;
       tool[10]->setGeometry(740,200,tool[0]->width(),tool[0]->height());
       tool[10]->x=740,tool[10]->y=200;
       //移动、道具、死亡
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
           if(tool[0]->x-kid1->x<30&&kid1->y>tool[0]->y&&istool[0]==false){
               istool[0]=true;
               this->toolevent(0);}
           if(tool[1]->x-kid1->x<30&&kid1->y>tool[1]->y&&istool[1]==false){
               istool[1]=true;
               this->toolevent(1);}
           if(tool[2]->x-kid1->x>=-10&tool[2]->x-kid1->x<=-5&&kid1->y>tool[2]->y&&istool[2]==false){
               istool[2]=true;
               istool[3]=true;
               this->toolevent(2);
               this->toolevent(3);
           }
           if(tool[4]->x-kid1->x>-15&&tool[4]->x-kid1->x<=0&&kid1->y>tool[4]->y&&istool[4]==false){
               istool[4]=true;
               istool[5]=true;
               this->toolevent(4);
               this->toolevent(5);
           }
           if(tool[6]->x-kid1->x<30&&kid1->y>tool[6]->y&&istool[6]==false){
               istool[6]=true;
               this->toolevent(6);}
           for(int i=7;i<10;i++){
               if(tool[i]->x-kid1->x>-30&&tool[i]->x-kid1->x<=0&&kid1->y<=tool[i]->y&&istool[i]==false){
                   istool[i]=true;
                   this->toolevent(i);
               }}
               if(tool[10]->x-kid1->x<30&&kid1->y<=tool[10]->y&&istool[10]==false){
                   istool[10]=true;
                   this->toolevent(10);}

          //是否死亡
          if(this->ishit()){
              death->show();
              dead=true;
          }
          //下落
          if(this->canfall2(kid1->x,kid1->y)&&kid1->jumptimes==0){
              qDebug()<<"fall";
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
          //返回上一地图
          if(kid1->x>97&&kid1->x<169&&kid1->y>380){
              this->hide();
            emit this->goback();
          }
      });
}
//地图加载
void map2::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/iwanna/map2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
//找坐标
void map2::mousePressEvent(QMouseEvent *event){
    qDebug()<<QString("x=%1,y=%2,kidx=%3,kidy=%4").arg(event->x()).arg(event->y()-251).arg(kid1->x).arg(kid1->y);
}
//下落事件
bool map2::canfall(int x, int y){
    for(int i=0;i<2;i++)
        if(x>top[i][0].x&&x<top[i][1].x&&y==top[i][0].y)
            return true;
        if(tempy-y>=75&&tempy>75)
            return true;
        if(tempy-y>=90&&tempy<=75)
            return true;
    return false;
}
bool map2::canfall2(int x, int y){
    for(int i=0;i<10;i++)
        if(x>bottom[i][1].x&&x<bottom[i+1][0].x&&(y==bottom[i][1].y||y==bottom[i+1][0].y))
            return true;
    if((x<bottom[2][0].x&&x>bottom[2][0].x-10&&y==bottom[2][0].y)||(x<bottom[3][0].x&&x>bottom[3][0].x-5&&y==bottom[3][0].y)||(x<bottom[10][0].x&&x>bottom[10][0].x-10&&y==bottom[10][0].y)||(x>bottom[4][1].x&&x<bottom[4][1].x+10&&y==bottom[4][1].y)||(x>bottom[5][1].x&&x<bottom[5][1].x+10&&y==bottom[5][1].y))
        return true;
    return false;
}
void map2::fall(){
    QTimer *time3 = new QTimer(this);//下落计时器
    time3->start(5);
    connect(time3,&QTimer::timeout,[=](){
        for(int i=0;i<11;i++)
            if(kid1->x>=bottom[i][0].x&&kid1->x<=bottom[i][1].x&&kid1->y==bottom[i][0].y){
                time3->stop();
                kid1->y-=1;
                kid1->jumptimes=0;//已经触底，重新激活跳跃事件
            }
        kid1->y+=1;
    });
}
//道具事件
void map2::toolevent(int i){
    QTimer *time3;
    time3 = new QTimer(this);
    time3->start(5);
    connect(time3,&QTimer::timeout,[=](){
        if(i<7){
            tool[i]->y+=2;
            tool[i]->move(tool[i]->x,tool[i]->y);
            if(tool[i]->y>450){
               time3->stop();
               if(i==0)tool[i]->x=0;
               tool[i]->y=500;
               tool[i]->move(tool[i]->x,tool[i]->y);
            }
        }
        else{
            tool[i]->y-=2;
            tool[i]->move(tool[i]->x,tool[i]->y);
            if(tool[i]->y<-280){
                time3->stop();
                tool[i]->y=-300;
                tool[i]->move(tool[i]->x,tool[i]->y);
            }
        }
    });
}
//键盘事件
void map2::keyPressEvent(QKeyEvent *ev){
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
        if(kid1->x>37||(kid1->x>-5&&kid1->y<=75))kid1->x-=5;
        if(kid1->pos!=1)kid1->pos=1;
        else kid1->pos=2;
        break;
    case Qt::Key_Right:
        if(dead)return;
        if(kid1->x<=646||(kid1->x>=646&&kid1->x<=679&&kid1->y<=306)||(kid1->y<=273&&kid1->x<=747))kid1->x+=5;
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
//            if(bullet1->y>=-105&&bullet1->y<=-25&&bullet1->x<=325&&bullet1->x>=315){
//                word[0]->hide();
//                word[1]->show();
//            }
//            else if(bullet1->y>=32&&bullet1->y<=96&&bullet1->x<=515&&bullet1->x>=505){
//                    word[1]->hide();
//                    word[2]->show();
//                }
//            else if(bullet1->y>=160&&bullet1->y<=225&&bullet1->x<=422&&bullet1->x>=412){
//                    word[2]->hide();
//                }
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
    {   if((tool[0]->y==229||tool[0]->y==500)&&(tool[1]->y==252||tool[1]->y==500)&&(tool[2]->y==230||tool[2]->y==500)&&(tool[3]->y==235||tool[3]->y==500)&&(tool[4]->y==250||tool[4]->y==500)&&(tool[5]->y==238||tool[5]->y==500)&&(tool[6]->y==215||tool[6]->y==500)&&(tool[7]->y==206||tool[7]->y==-300)&&(tool[8]->y==229||tool[8]->y==-300)&&(tool[9]->y==230||tool[9]->y==-300)&&(tool[10]->y==200||tool[10]->y==-300)){
        death->hide();
        kid1->move(47,339);
        kid1->x=47;
        kid1->y=339;
        kid1->pos=3;
        kid1->jumptimes=0;
        tempx=kid1->x;
        tempy=kid1->y;
        for(int i=0;i<11;i++)
            istool[i]=false;
        tool[0]->setGeometry(94,229,tool[0]->width(),tool[0]->height());
        tool[0]->x=94;tool[0]->y=229;
        tool[1]->setGeometry(262,252,tool[0]->width(),tool[0]->height());
        tool[1]->x=262,tool[1]->y=252;
        tool[2]->setGeometry(345,230,tool[0]->width(),tool[0]->height());
        tool[2]->x=345,tool[2]->y=230;
        tool[3]->setGeometry(369,235,tool[0]->width(),tool[0]->height());
        tool[3]->x=369,tool[3]->y=235;
        tool[4]->setGeometry(440,250,tool[0]->width(),tool[0]->height());
        tool[4]->x=440,tool[4]->y=250;
        tool[5]->setGeometry(485,238,tool[0]->width(),tool[0]->height());
        tool[5]->x=485,tool[5]->y=238;
        tool[6]->setGeometry(672,215,tool[0]->width(),tool[0]->height());
        tool[6]->x=672,tool[6]->y=215;
        tool[7]->setGeometry(308,206,tool[0]->width(),tool[0]->height());
        tool[7]->x=308,tool[7]->y=206;
        tool[8]->setGeometry(502,229,tool[0]->width(),tool[0]->height());
        tool[8]->x=502,tool[8]->y=229;
        tool[9]->setGeometry(607,230,tool[0]->width(),tool[0]->height());
        tool[9]->x=607,tool[9]->y=230;
        tool[10]->setGeometry(740,200,tool[0]->width(),tool[0]->height());
        tool[10]->x=740,tool[10]->y=200;
        dead=false;
        break;
    }}
    default:;
    }
 }
//死亡事件
bool map2::ishit(){
    for(int i=0;i<11;i++){
        if(kid1->y-tool[i]->y<=25&kid1->y-tool[i]->y>=-10&&kid1->x-tool[i]->x>=-20&&kid1->x-tool[i]->x<=10)
            return true;
    }
    return false;
}
//人物不动时图片显示
bool map2::xischange(int x){
    if(x!=kid1->x)return true;
    return false;
}
