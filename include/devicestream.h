#ifndef DEVICESTREAM_H
#define DEVICESTREAM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <enums.h>

template<class T>
class smanip;

class DeviceStream
{
public:
    DeviceStream(std::string device);
    ~DeviceStream();
    DeviceStream& operator<<(std::string);
    DeviceStream& operator<<(float);
    DeviceStream& operator<<(WaveForm);
    DeviceStream& operator<<(Channel);
    DeviceStream& operator<<(OutputState);
    DeviceStream& operator<<(DeviceStream& (*pf)(DeviceStream&));
    template<typename T>
    DeviceStream& operator<<(smanip<T>);

    friend DeviceStream& endl(DeviceStream&);
    friend DeviceStream& sprec_(DeviceStream&, int);

private:
    std::string device;
    std::fstream file;
    std::stringstream buffer;
};

template<class T>
class smanip {
public:
    smanip(DeviceStream& (*pf)(DeviceStream&, T), T);
    DeviceStream& manipulate(DeviceStream&);

private:
    DeviceStream& (*pf)(DeviceStream&, T);
    T arg;
};


DeviceStream& endl(DeviceStream&);
smanip<int> setprecision(int);



#endif // DEVICESTREAM_H
