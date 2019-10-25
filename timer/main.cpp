#include "timer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Timer timer;
    timer.show();
    return a.exec();
}
