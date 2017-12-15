#include "user_button.h"
#include "widget.h"

#include <QWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QString>
#include <QSize>
#include <QIcon>
#include <QPixmap>

Button::Button(QWidget *parent): QPushButton(parent){
    time = new QTimer(this); //recover the status of the hammer
    time->connect(time,SIGNAL(timeout()),this, SLOT(ham_up())); //connect time with hammer up event
    
    this->num_pic = 0; //initialize the number of pictures
}

void Button::hammer(){
    if(this->num_pic != 0){
        this->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/hit.png"));
        Widget::score++;
    }
}


void Button::mousePressEvent(QMouseEvent *e){
    this->setCursor(QCursor(QPixmap("D:/Academic/Wrack-A-Pokemon/hit.png")));
    time->start(100); //set up the duration of the action hit (int msec)
    this->hammer();
}

void Button::ham_up(){
    this->setCursor(QCursor(QPixmap("D:/Academic/Wrack-A-Pokemon/hammer.png")));
}
