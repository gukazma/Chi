#include "Widgets/MainWindow.h"
#include <Chi/Primitives/Timer.hpp>
#include <Chi/SFM/InitImageListing.h>
#include <QApplication>
#include <iostream>
#include <thread>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow* mainwindow = new MainWindow;
    mainwindow->showMaximized();

    return app.exec();
}
