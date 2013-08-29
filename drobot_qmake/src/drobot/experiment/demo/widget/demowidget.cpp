#include "demowidget.h"
#include "ui_demowidget.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace widget {

DemoWidget::DemoWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::DemoWidget)
{
    ui->setupUi(this);
}

DemoWidget::~DemoWidget()
{
    delete ui;
}

} // namespace widget
} // namespace demo
} // namespace experiment
} // namespace drobot
