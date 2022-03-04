#include "jbvwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JBVWindow w;
    w.show();
    return a.exec();
}
