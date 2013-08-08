#include "capture.h"

namespace drobot {
namespace device {
namespace vision {
namespace capture {

Capture::Capture() : _frame()
{

}


Capture::~Capture()
{

}

void
Capture::start()
{
    init();
    _captureThread = new boost::thread( boost::bind(&Capture::execute, this) );
}


void
Capture::stop()
{
    _captureThread->interrupt();
    terminate();
}


cv::Mat
Capture::getFrame()
{

    return _frame;
}

}
}
}
}
