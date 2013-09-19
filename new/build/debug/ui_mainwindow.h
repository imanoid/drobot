/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

namespace drobot {
namespace widget {

class Ui_MainWindow
{
public:
    QWidget *mainWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hbox;
    QVBoxLayout *launcher;
    QTabWidget *tasks;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *drobot__widget__MainWindow)
    {
        if (drobot__widget__MainWindow->objectName().isEmpty())
            drobot__widget__MainWindow->setObjectName(QString::fromUtf8("drobot__widget__MainWindow"));
        drobot__widget__MainWindow->resize(800, 600);
        mainWidget = new QWidget(drobot__widget__MainWindow);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        gridLayout = new QGridLayout(mainWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hbox = new QHBoxLayout();
        hbox->setObjectName(QString::fromUtf8("hbox"));
        launcher = new QVBoxLayout();
        launcher->setObjectName(QString::fromUtf8("launcher"));

        hbox->addLayout(launcher);

        tasks = new QTabWidget(mainWidget);
        tasks->setObjectName(QString::fromUtf8("tasks"));

        hbox->addWidget(tasks);


        gridLayout->addLayout(hbox, 0, 0, 1, 1);

        drobot__widget__MainWindow->setCentralWidget(mainWidget);
        menubar = new QMenuBar(drobot__widget__MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        drobot__widget__MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(drobot__widget__MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        drobot__widget__MainWindow->setStatusBar(statusbar);

        retranslateUi(drobot__widget__MainWindow);

        QMetaObject::connectSlotsByName(drobot__widget__MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *drobot__widget__MainWindow)
    {
        drobot__widget__MainWindow->setWindowTitle(QApplication::translate("drobot::widget::MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

} // namespace widget
} // namespace drobot

namespace drobot {
namespace widget {
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
} // namespace widget
} // namespace drobot

#endif // UI_MAINWINDOW_H
