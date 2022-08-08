#ifndef STARTSCENE_H
#define STARTSCENE_H
#include <QMainWindow>
#include"map1.h"
class startscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit startscene(QWidget *parent = nullptr);
    map1 *map01 = nullptr;
signals:

public slots:
};

#endif // STARTSCENE_H
