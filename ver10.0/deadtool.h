#ifndef DEADTOOL_H
#define DEADTOOL_H
#include<QLabel>
#include <QWidget>

class deadtool : public QLabel
{
    Q_OBJECT
public:
    //explicit deadtool(QWidget *parent = nullptr);
    deadtool(QString toolimg);
    int x;
    int y;
signals:

public slots:
};

#endif // DEADTOOL_H
