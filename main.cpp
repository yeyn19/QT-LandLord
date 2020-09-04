#include "mainwindow.h"
#include "myconnect.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("慈 善 赌 王");
    w.show();
    return a.exec();
}
