#ifndef KID_H
#define KID_H
#include<QLabel>
#include <QWidget>
#include<QTimer>
class kid : public QLabel
{
    Q_OBJECT
public:
    //explicit kid(QWidget *parent = nullptr);
    kid(QString kidimg);
    void imgchange();//移动图片切换
    int x;
    int y;
    int pos;//加载哪张图片
    int jumptimes;//跳跃次数
signals:

public slots:
};

#endif // KID_H
