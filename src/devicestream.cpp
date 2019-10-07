#include "devicestream.h"
#include <iomanip>
#include <chrono>
#include <thread>

DeviceStream::DeviceStream(std::string device)
{
    this->device = device;
    file.open(this->device, std::ios::in | std::ios::out);
    if(!file)
        throw std::runtime_error("Cannot open device.");
}

DeviceStream::~DeviceStream() {
    file.close();
}

DeviceStream& DeviceStream::operator<<(const std::string s) {
    buffer << s;
    return *this;
}

DeviceStream& DeviceStream::operator<<(const float f) {
    buffer << std::setprecision(6) << f;
    return *this;
}

DeviceStream& DeviceStream::operator<<(void (*pf)()) {
    file << buffer.str() << std::endl;
    buffer.str("");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return *this;
}

void DeviceStream::endl() {}
