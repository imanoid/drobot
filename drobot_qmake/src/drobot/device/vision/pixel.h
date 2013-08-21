#ifndef DROBOT_DEVICE_VISION_PIXEL_H
#define DROBOT_DEVICE_VISION_PIXEL_H

namespace drobot {
namespace device {
namespace vision {

struct Pixel {
    Pixel() {}

    Pixel(int red, int green, int blue) {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    Pixel(int brightness) {
        this->brightness;
    }

    Pixel(int red, int green, int blue, int brightness) {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->brightness = brightness;
    }

    int red;
    int green;
    int blue;
    int brightness;
};

} // namespace vision
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VISION_PIXEL_H
