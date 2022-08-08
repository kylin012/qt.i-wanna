#include "kid.h"
kid::kid(QString kidimg){
    QPixmap pix;
    pix.load(kidimg);
    this->setPixmap(pix);
    this->x=133;
    this->y=-155;
    this->pos=3;
    this->jumptimes=0;
}
void kid::imgchange(){
    QPixmap pix;
    QString str=QString(":/iwanna/kid%1").arg(this->pos);
    pix.load(str);
    this->setPixmap(pix);
}


