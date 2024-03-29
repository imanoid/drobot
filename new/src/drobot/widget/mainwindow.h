#ifndef DROBOT_WIDGET_MAINWINDOW_H
#define DROBOT_WIDGET_MAINWINDOW_H

#include <QMainWindow>
#include "../program/programmanager.h"

namespace drobot {
namespace widget {

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void onProgramLaunch();
private:
    Ui::MainWindow* ui;
    drobot::program::ProgramManager* _programManager;
};


} // namespace widget
} // namespace drobot
#endif // DROBOT_WIDGET_MAINWINDOW_H
