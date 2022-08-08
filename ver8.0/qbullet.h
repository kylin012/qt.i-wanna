#ifndef QBULLET_H
#define QBULLET_H

#include <QWidget>
#include<QLabel>
class Qbullet : public QLabel
{
    Q_OBJECT
public:
   // explicit Qbullet(QWidget *parent = nullptr);
    Qbullet(QString bulletimg);
        int x;
        int y;
        int pos;
signals:
public slots:
};

#endif // QBULLET_H
