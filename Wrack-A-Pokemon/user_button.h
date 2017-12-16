#ifndef USER_BUTTON_H
#define USER_BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QLabel>

class Button: public QPushButton{
    Q_OBJECT
public:
    Button(QWidget *parent);
    
    //record the number of pictures
    bool is_pokemon;

    //void hammer();
    void mousePressEvent(QMouseEvent *e);

    ~Button();

public slots:
    
    void ham_up();

private:
    QTimer *time;
    Button *buttonArray;
    QLabel *score_label;
};


#endif // USER_BUTTON_H
