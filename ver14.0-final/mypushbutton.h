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
    void zoom1();
    void zoom2();
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
