#include "widget.h"
#include "user_button.h"

#include <QIcon>
#include <QTimer>
#include <QCursor>
#include <QPixmap>
#include <QSize>
#include <QDebug>

Widget::Widget(QWidget *parent):QWidget(parent){
    initial_beat(5);
    time = QTime::currentTime();
    qsrand(time.msec()+ time.second()*1000);
    //random access
    srand[0] = 0;
    srand[1] = 0;
    srand[2] = 0;
    srand[3] = 0;
    srand[4] = 0;

    timer = new QTimer(this);
    timer->connect(timer,SIGNAL(timeout()),this,SLOT(start_game()));
    timer->start(200);

    QPixmap qp;
    qp.load("D:/Academic/Wrack-A-Pokemon/hammer.png");
    this->setCursor(QCursor(qp));
}

void Widget::initial_beat(int n){
    int counter = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            buttons[counter] = new Button(this);
            buttons[counter] -> resize(200,200);
            buttons[counter] -> move(200*j, 200*i);
            buttons[counter] -> setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/hole.jpg"));
            buttons[counter] -> setIconSize(QSize(200,200));
            counter++;
        }
    }
    for(int i = 0; i < 6; i++){
        icons[i] = new QIcon("D:/Academic/Wrack-A-Pokemon/Pikachu.jpg" );
    }
}

void Widget::start_game(){
    this->setCursor(QCursor(QPixmap("D:/Academic/Wrack-A-Pokemon/hammer.png"))); //release the mouse
    for(int i = 0; i < 5; i++){
        if(buttons[srand[i]]->num_pic < 6){
            buttons[srand[i]] -> setIcon(*icons[buttons[srand[i]]->num_pic++]);
            buttons[srand[i]] -> setIconSize(QSize(200,200));
        }
        else{
            buttons[srand[i]]->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/hole.jpg"));
            buttons[srand[i]]->setIconSize(QSize(200,200));
            buttons[srand[i]]->num_pic = 0;
            srand[i] = qrand()%25;

            //score
            setWindowTitle("Welcome to Wrack-A-Pokemon! Your Score is :"+QString::number(score));
        }
    }
}

Button **Widget::getBeat(){
    return buttons;
}

Widget::~Widget(){
    delete[] buttons;
    delete[] icons;
    delete timer;
}



