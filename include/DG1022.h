#ifndef DG1022_H
#define DG1022_H

#include <iostream>
#include "devicestream.h"

enum class WaveForm { SINUSOID, SQUARE, RAMP, PULSE, NOISE, DC };
enum class Channel { CHANNEL1, CHANNEL2 };
enum class OutputState {ON, OFF};

class DG1022
{
public:
    DG1022(std::string device);
    ~DG1022();
    void setOutputOn(Channel chan = Channel::CHANNEL1);
    void setOutputOff(Channel chan = Channel::CHANNEL1);
    void setFrequency(float f, Channel chan = Channel::CHANNEL1);
    void setWaveForm(WaveForm f, Channel chan = Channel::CHANNEL1);
    void setVoltage(float v, Channel chan = Channel::CHANNEL1);
    void setPhase(float p, Channel chan = Channel::CHANNEL1);

    static void sleep(int ms);

private:
    std::string device;
    DeviceStream dstream;
};

#endif // DG1022_H
