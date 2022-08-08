#include "mainscene.h"
#include "ui_mainscene.h"
#include<QMessageBox>
#include<QMovie>
#include<QLabel>
mainscene::mainscene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainscene)
{
    ui->setupUi(this);
    //界面设置
    setFixedSize(799,620);
    setWindowIcon(QIcon(":/iwanna/icon.png"));
    setWindowTitle("I wanna be the guyyyyyyyy");
    //菜单设置
    connect(ui->actionquit,&QAction::triggered,[=](){
        if(QMessageBox::Yes==QMessageBox::warning(this,"警告","确认退出？",QMessageBox::Yes|QMessageBox::No))
            this->close();

    });
    connect(ui->actionhelp,&QAction::triggered,[=](){
        QMessageBox::about(this,"操作指南","");
    });
    //开场动画
    QLabel *op1 = new QLabel(this);
    op1->setGeometry(0,15,this->width(),this->height());
    QMovie *movie = new QMovie(":/iwanna/op1.gif");
    op1->setMovie(movie);
    movie->start();
    startsc = new startscene;

}
//开始界面
void mainscene::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
     this->hide();
     startsc->show();
    }
}
mainscene::~mainscene()
{
    delete ui;
}
