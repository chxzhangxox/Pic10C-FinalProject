#ifndef WIDGET_H
#define WIDGET_H

#include "user_button.h"
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QIcon>

class Widget: public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    Button **getBeat();
    ~Widget();
    
    void initial_beat(int n);
    static int score;

public slots:
    void start_game();

private:
    Button *buttons[25];
    QIcon *icons[6];
    
    QTimer *timer; //use it to refresh the interface
    QTime time;
    int srand[5];
    
    
};

#endif // WIDGET_H
