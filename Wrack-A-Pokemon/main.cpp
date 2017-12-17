#include "widget.h"
#include <QApplication>
#include <QSound>

int Widget::score;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w, *pW;
    pW = &w;

    w.setWindowTitle("Wrack-A-Pokemon");
    w.setFixedSize(1200,1000);
    w.show();

    return a.exec();
}
