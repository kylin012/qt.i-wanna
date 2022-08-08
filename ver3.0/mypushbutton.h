#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit mypushbutton(QWidget *parent = nullptr);
    mypushbutton (QString imgpath);
    QString imgpath;
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
