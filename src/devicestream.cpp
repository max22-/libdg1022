#include <DG1022/devicestream.h>
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

DeviceStream& DeviceStream::operator<<(WaveForm wf) {
    switch (wf) {
        case WaveForm::SINUSOID:
            buffer << "SIN";
            break;
        case WaveForm::SQUARE:
            buffer << "SQU";
            break;
        case WaveForm::RAMP:
            buffer << "RAMP";
            break;
        case WaveForm::PULSE:
            buffer << "PULS";
            break;
        case WaveForm::NOISE:
            buffer << "NOIS";
            break;
        case WaveForm::DC:
            buffer << "DC";
            break;
        case WaveForm::USER:
            buffer << "USER";
            break;
    }
    return *this;
}

DeviceStream& DeviceStream::operator<<(Channel c) {
    switch (c) {
        case Channel::CHANNEL1:
            break;
         case Channel::CHANNEL2:
            buffer << ":CH2";
            break;
    }
    return *this;
}

DeviceStream& DeviceStream::operator<<(OutputState os) {
    switch (os) {
        case OutputState::ON:
            buffer << "ON";
            break;
        case OutputState::OFF:
            buffer << "OFF";
            break;
    }
    return *this;
}

DeviceStream& DeviceStream::operator<<(DeviceStream& (*pf)(DeviceStream&)) {
    return pf(*this);
}

template<typename T>
DeviceStream& DeviceStream::operator<<(smanip<T> m) {
    return m.manipulate(*this);
}

DeviceStream& endl(DeviceStream& dstrm) {
    dstrm.file << dstrm.buffer.str() << std::endl;
    dstrm.buffer.str("");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    dstrm << setprecision(6);
    return dstrm;
}

template <typename T>
smanip<T>::smanip(DeviceStream& (*pf)(DeviceStream&, T), T arg) : pf(pf), arg(arg) {
}

template <typename T>
DeviceStream & smanip<T>::manipulate(DeviceStream& strm) {
    return pf(strm, arg);
}

DeviceStream& sprec_(DeviceStream& strm, int p) {
    strm.buffer << std::setprecision(p);
    return strm;
}

smanip<int> setprecision(int p) {
    return smanip<int>(sprec_, p);
}
