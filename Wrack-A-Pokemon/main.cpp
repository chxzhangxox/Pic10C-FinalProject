#include "widget.h"
#include <QApplication>

int Widget::score;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w, *pW;
    pW = &w;

    w.setWindowTitle("Wrack-A-Pokemon");
    w.setFixedSize(1000,1000);
    w.show();

    return a.exec();
}
