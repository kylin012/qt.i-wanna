#ifndef KID_H
#define KID_H
#include<QLabel>
#include <QWidget>

class kid : public QLabel
{
    Q_OBJECT
public:
    //explicit kid(QWidget *parent = nullptr);
    kid(QString kidimg);
    int x;
    int y;
signals:

public slots:
};

#endif // KID_H
