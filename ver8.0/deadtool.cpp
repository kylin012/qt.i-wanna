#include "deadtool.h"
deadtool::deadtool(QString toolimg){
    QPixmap pix;
    pix.load(toolimg);
    this->setPixmap(pix);
}
