#ifndef DEVICESTREAM_H
#define DEVICESTREAM_H

#include <iostream>
#include <fstream>
#include <sstream>

class DeviceStream
{
public:
    DeviceStream(std::string device);
    ~DeviceStream();
    DeviceStream& operator<<(std::string);
    DeviceStream& operator<<(float);
    DeviceStream& operator<<(DeviceStream& (*pf)(DeviceStream&));

    friend DeviceStream& endl(DeviceStream&);

private:
    std::string device;
    std::fstream file;
    std::stringstream buffer;
};

DeviceStream& endl(DeviceStream&);

#endif // DEVICESTREAM_H
