#ifndef USER_BUTTON_H
#define USER_BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QLabel>
#include <QApplication>

class Button: public QPushButton{
    Q_OBJECT
public:
    Button(QWidget *parent);
    
    //detect if there is a pokemon
    bool is_pokemon;

    //void hammer();
    void mousePressEvent(QMouseEvent *e);

    ~Button();

public slots:
    
    void ham_up();

private:
    QTimer *time;
};


#endif // USER_BUTTON_H
