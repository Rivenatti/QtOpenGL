#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#define st "Programujemy w C++"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
 //w.show();

    QLabel *label = new QLabel(QObject :: tr(st));
    label -> show();

    return a.exec();
}
