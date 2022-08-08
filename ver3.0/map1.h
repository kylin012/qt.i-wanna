#ifndef MAP1_H
#define MAP1_H
#include<QMouseEvent>
#include <QMainWindow>
#include"kid.h"
class map1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit map1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:
};

#endif // MAP1_H
