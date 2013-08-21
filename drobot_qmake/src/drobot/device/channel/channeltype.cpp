#include "channeltype.h"

namespace drobot {
namespace device {
namespace channel {

ChannelType channelTypeFromString(std::string name) {
    if (name.compare("INPUT") == 0) {
        return INPUT;
    } else if (name.compare("OUTPUT") == 0) {
        return OUTPUT;
    }
}

std::string channelTypeToString(ChannelType type) {
    switch (type) {
    case INPUT:
        return std::string("INPUT");
    case OUTPUT:
        return std::string("OUTPUT");
    }
}

}
}
}
