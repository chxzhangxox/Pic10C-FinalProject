#ifndef WIDGET_H
#define WIDGET_H

#include "user_button.h"
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QIcon>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>

class Widget: public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    
    void button_init(int n);
    void func_button();
    static int score;

     ~Widget();

public slots:
    void start_game();
    void set_timer();

private:
    Button *buttons[25];
    QIcon *pokemons[7];
    QMediaPlayer *music;
    
    QTimer *timer;
    QTime time;
    int index[5];
    
    QPushButton *start;
    QPushButton *end;
    QPushButton *score_t;
    QPushButton *title;
    QPushButton *tail;
};

#endif // WIDGET_H
