#include "./view/mainwindow.h"
#include "./app/msapp.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MSApp app;
    app.Init(w);
    return a.exec();
}
