#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>
#include <QPushButton>
#include <string>

namespace drobot {
namespace widget {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _programManager = new drobot::program::ProgramManager();
    std::vector<std::string> programs = _programManager->listProgramFactoryNames();
    for (int i = 0; i < programs.size(); i++) {
        std::string programName = programs[i];

        QPushButton* programButton = new QPushButton(QString::fromStdString(programName), this->ui->mainWidget);
        QObject::connect(programButton, SIGNAL(clicked()),this, SLOT(onProgramLaunch()));

        this->ui->launcher->addWidget(programButton);
    }
}

MainWindow::~MainWindow()
{
    delete _programManager;
    delete ui;
}

void MainWindow::onProgramLaunch() {
    std::string name = ((QPushButton*)sender())->text().toStdString();
    drobot::program::Program* program = _programManager->launchProgram(name);
    this->ui->tasks->addTab(program->getWidget(), QString::fromStdString(program->getName()));
}

} // namespace widget
} // namespace drobot
