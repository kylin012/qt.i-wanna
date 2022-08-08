#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QRect>
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
void mypushbutton::zoom1(){
    QPropertyAnimation *anim = new QPropertyAnimation(this,"geometry");
    anim->setDuration(200);
    anim->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    anim->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    anim->setEasingCurve(QEasingCurve::OutBounce);
    anim->start();
}
void mypushbutton::zoom2(){
    QPropertyAnimation *anim = new QPropertyAnimation(this,"geometry");
    anim->setDuration(200);
    anim->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    anim->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    anim->setEasingCurve(QEasingCurve::OutBounce);
    anim->start();
}
