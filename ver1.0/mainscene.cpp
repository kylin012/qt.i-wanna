#include "mainscene.h"
#include "ui_mainscene.h"
#include<QMessageBox>
mainscene::mainscene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainscene)
{
    ui->setupUi(this);

    setFixedSize(799,620);
    setWindowIcon(QIcon(":/iwanna/icon.png"));
    setWindowTitle("I wanna be the guyyyyyyyy");
    connect(ui->actionquit,&QAction::triggered,[=](){
        if(QMessageBox::Yes==QMessageBox::warning(this,"警告","确认退出？",QMessageBox::Yes|QMessageBox::No))
            this->close();

    });
}

mainscene::~mainscene()
{
    delete ui;
}
