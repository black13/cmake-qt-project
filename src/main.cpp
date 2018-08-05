#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //call_M_foo(&w,1);
    
    w.show();
    
    return a.exec();
}
