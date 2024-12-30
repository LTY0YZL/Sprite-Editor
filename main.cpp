/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * The main class for starting
**/
#include <QApplication>
#include "mainwindow.h"
#include "Sprite.h"


//main of spritor
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sprite sprite;
    MainWindow w(sprite);
    w.show();
    return a.exec();
}
