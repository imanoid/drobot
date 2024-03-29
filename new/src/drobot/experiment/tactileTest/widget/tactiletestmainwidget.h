#ifndef DROBOT_EXPERIMENT_TACTILETEST_WIDGET_MAINWIDGET_H
#define DROBOT_EXPERIMENT_TACTILETEST_WIDGET_MAINWIDGET_H

#include <QScrollArea>

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace widget {

namespace Ui {
class MainWidget;
}

class MainWidget : public QScrollArea
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    
private:
    Ui::MainWidget *ui;
};


} // namespace widget
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
#endif // DROBOT_WIDGET_TACTILETESTWIDGET_H
