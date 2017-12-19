#include "widget.h"
#include "user_button.h"


#include <QIcon>
#include <QTimer>
#include <QCursor>
#include <QPixmap>
#include <QSize>
#include <QMediaPlayer>

Widget::Widget(QWidget *parent):QWidget(parent){
    button_init(5);
    func_button();

    time = QTime::currentTime();
    qsrand(time.msec() + time.second()*1000);

    //initialize indexes
    for (int i = 0; i < 5; i++){
    index[i] = 0;
    }

    timer = new QTimer(this);

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("D:/Academic/Wrack-A-Pokemon/pokemon.mp3"));
    music->play();

    connect(start,SIGNAL(clicked(bool)),this,SLOT(set_timer()));
    timer->connect(timer,SIGNAL(timeout()),this,SLOT(start_game()));

    connect(end,SIGNAL(clicked(bool)),this,SLOT(close()));

    //setup cursor
    QPixmap cursor_im;
    cursor_im.load("D:/Academic/Wrack-A-Pokemon/hammer.png");
    this->setCursor(QCursor(cursor_im));
}

void Widget::button_init(int n){
    int rows = 0;
    //initialize 25 buttons (resize them and set icons)
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            buttons[rows] = new Button(this);
            buttons[rows] -> resize(200,200);
            buttons[rows] -> move(200*j, 200*i);
            buttons[rows] -> setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/hole.jpg"));
            buttons[rows] -> setIconSize(QSize(210,210));

            rows++;
        }
    }


    //setup the pokemon images we wish to import
    for(int i = 0; i < 7; i++){
        pokemons[i] = new QIcon("D:/Academic/Wrack-A-Pokemon/"+QString::number(i)+".jpg" );
    }
}

void Widget::func_button(){
    start = new QPushButton(this);
    start->resize(400,200);
    start->move(200*5,200*1);
    start->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/startbutton.jpg"));
    start->setIconSize(QSize(400,220));

    end = new QPushButton(this);
    end->resize(400,200);
    end->move(200*5,200*3);
    end->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/endbutton.jpg"));
    end->setIconSize(QSize(400,220));

    score_t = new QPushButton(this);
    score_t->resize(400,200);
    score_t->move(200*5,200*2);
    score_t->setStyleSheet("background-image: url(D:/Academic/Wrack-A-Pokemon/blank.jpg);""border:none");
    score_t->setText("Your Score is 0");

    title = new QPushButton(this);
    title->resize(400,200);
    title->move(200*5,200*0);
    title->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/pokelogo"));
    title->setIconSize(QSize(450,210));

    tail = new QPushButton(this);
    tail->resize(400,200);
    tail->move(200*5,200*4);
    tail->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/tail"));
    tail->setIconSize(QSize(400,220));

}


void Widget::start_game(){
    this->setCursor(QCursor(QPixmap("D:/Academic/Wrack-A-Pokemon/hammer.png")));

    for(int i = 0; i < 5; i++){
        //randomly determine if there is a pokemon there
        buttons[index[i]]->is_pokemon = qrand()%2;
        if(buttons[index[i]]->is_pokemon == 1){
            buttons[index[i]] -> setIcon(*pokemons[qrand()%7]);
            buttons[index[i]] -> setIconSize(QSize(210,210));
        }
        else{
            buttons[index[i]]->setIcon(QIcon("D:/Academic/Wrack-A-Pokemon/hole.jpg"));
            buttons[index[i]]->setIconSize(QSize(210,210));
            index[i] = qrand()%25;
        }

        //output scores
        setWindowTitle("Welcome to Wrack-A-Pokemon! Your Score is :"+QString::number(score));
        score_t->setText("Your Score is: " +QString::number(score));
    }
}

void Widget::set_timer(){
    timer->start(1000);
}

Widget::~Widget(){
    delete[] pokemons;
    delete[] buttons;
    delete timer;
    delete music;
    delete start;
    delete score_t;
    delete end;
}



