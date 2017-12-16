#ifndef WIDGET_H
#define WIDGET_H

#include "user_button.h"
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QIcon>
#include <QLabel>

class Widget: public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    
    void button_init(int n);
    static int score;

     ~Widget();

public slots:
    void start_game();

private:
    Button *buttons[25];
    QIcon *pokemons[7];
    
    QTimer *timer; //use it to refresh the interface
    QTime time;
    int index[5];
    
    
};

#endif // WIDGET_H
