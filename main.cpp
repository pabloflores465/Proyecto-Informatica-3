//#include "mainwindow.h"
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;

    //MainWindow w;
    d.show();

    //w.show();
    return a.exec();
}
