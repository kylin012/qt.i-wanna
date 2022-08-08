#include "kid.h"
kid::kid(QString kidimg){
    QPixmap pix;
    pix.load(kidimg);
    this->setPixmap(pix);
}
