#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>

namespace Ui {
class mainscene;
}

class mainscene : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainscene(QWidget *parent = 0);
    ~mainscene();

private:
    Ui::mainscene *ui;
};

#endif // MAINSCENE_H
