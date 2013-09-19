#include "tactiletestmainwidget.h"
#include "ui_tactiletestmainwidget.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace widget {

MainWidget::MainWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}


} // namespace widget
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
