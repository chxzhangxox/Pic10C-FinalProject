#ifndef USER_BUTTON_H
#define USER_BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QTimer>

class Button: public QPushButton{
    Q_OBJECT
public:
    Button(QWidget *parent);
    
    //record the number of pictures
    int num_pic;
    void hammer();
    void mousePressEvent(QMouseEvent *e);

public slots:
    
    void ham_up();

private:
    QTimer *time;
    Button *beat;
};


#endif // USER_BUTTON_H
