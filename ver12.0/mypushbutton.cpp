#include "mypushbutton.h"
#include<QDebug>
mypushbutton::mypushbutton(QString imgpath){
    this->imgpath = imgpath;
    QPixmap pix;
    bool ret = pix.load(imgpath);
    if(!ret){
        qDebug()<<"fail";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border-style:none}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
