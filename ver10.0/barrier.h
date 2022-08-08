#ifndef BARRIER_H
#define BARRIER_H

#include <QWidget>

class barrier : public QWidget
{
    Q_OBJECT
public:
    explicit barrier(QWidget *parent = nullptr);
    int x;
    int y;
    void dopos(int x1,int y1);
signals:

public slots:
};

#endif // BARRIER_H
