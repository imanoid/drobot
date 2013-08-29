#ifndef DROBOT_EXPERIMENT_DEMO_WIDGET_DEMOWIDGET_H
#define DROBOT_EXPERIMENT_DEMO_WIDGET_DEMOWIDGET_H

#include <QScrollArea>

namespace drobot {
namespace experiment {
namespace demo {
namespace widget {

namespace Ui {
class DemoWidget;
}

class DemoWidget : public QScrollArea
{
    Q_OBJECT
    
public:
    explicit DemoWidget(QWidget *parent = 0);
    ~DemoWidget();
    
private:
    Ui::DemoWidget *ui;
};


} // namespace widget
} // namespace demo
} // namespace experiment
} // namespace drobot
#endif // DROBOT_EXPERIMENT_DEMO_WIDGET_DEMOWIDGET_H
