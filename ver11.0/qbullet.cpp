#include "qbullet.h"
#include<QTimer>
Qbullet::Qbullet(QString bulletimg){
    QPixmap pix;
    pix.load(bulletimg);
    this->setPixmap(pix);
}

