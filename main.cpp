//#include "mainwindow.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login log_in;

    //MainWindow w;
    log_in.show();

    //w.show();
    return a.exec();
}
