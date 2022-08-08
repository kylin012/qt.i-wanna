#ifndef MAINSCENE_H
#define MAINSCENE_H
#include<QMouseEvent>
#include <QMainWindow>
#include"startscene.h"
namespace Ui {
class mainscene;
}

class mainscene : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainscene(QWidget *parent = 0);
    ~mainscene();
    virtual void mousePressEvent(QMouseEvent *event);
    startscene *startsc = nullptr;
private:
    Ui::mainscene *ui;
};

#endif // MAINSCENE_H
