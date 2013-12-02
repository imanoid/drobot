#include <QApplication>
#include "qglobal.h"
#include "widget/mainwindow.h"

#include <unistd.h>

int main( int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("Artificial Intelligence Laboratory, University of Zurich");
    app.setApplicationName("DRobot");

    drobot::widget::MainWindow win;
    win.showMaximized();

    return app.exec();
}
