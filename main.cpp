#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QTime>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     qsrand(QTime::currentTime().msec());

    QTranslator myTranslator;
    myTranslator.load(QLocale::Russian,"tetris","_");

    a.installTranslator(&myTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
