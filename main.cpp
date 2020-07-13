#include "./view/mainwindow.h"
#include "./app/msapp.h"
#include <QApplication>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MSApp app;
    app.Init(w);
    //qDebug()<<QDir::currentPath();
    return a.exec();
}
