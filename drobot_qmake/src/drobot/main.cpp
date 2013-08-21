#include <iostream>
#include <QApplication>
#include "qglobal.h"
#include "widget/mainwindow.h"
#include "device/devicemanager.h"
#include <phidget21.h>

int main( int argc, char* argv[]) {
   // Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("Trolltech");
    app.setApplicationName("Application Example");
    drobot::widget::MainWindow mainWin;
    mainWin.showMaximized();
    return app.exec();
}
