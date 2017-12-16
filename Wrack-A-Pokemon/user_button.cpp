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
    //setup a timer within the button
    time = new QTimer(this);

    //when time is out, we set the cursor back to hammer
    time->connect(time,SIGNAL(timeout()),this, SLOT(ham_up()));
    
    //initialize the number of pictures, use it to determine whether you hitted the pokemon or not
    this->is_pokemon = 0;
}


void Button::mousePressEvent(QMouseEvent *e){
    //record the score
    if(this->is_pokemon != 0){
        this->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/hit.png"));
        Widget::score++;
    }
}

void Button::ham_up(){
    this->setCursor(QCursor(QPixmap("D:/Academic/Wrack-A-Pokemon/hammer.png")));
}

Button::~Button(){
    delete time;
    delete buttonArray;
    delete score_label;
}
