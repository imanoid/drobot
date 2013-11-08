#include <iostream>
#include <QApplication>
#include "qglobal.h"
#include "widget/mainwindow.h"
#include <phidget21.h>

#include "device/actuator/phidgetsimpleboard.h"
#include <unistd.h>

int main( int argc, char* argv[]) {
   // Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("AIlab Zürich");
    app.setApplicationName("Drobot");
    drobot::widget::MainWindow mainWin;
    mainWin.showMaximized();
    return app.exec();
}
