#include "qutubedl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qutubedl w;
    w.show();

    return a.exec();
}
