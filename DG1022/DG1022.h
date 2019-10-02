#ifndef DG1022_H
#define DG1022_H

#include "DG1022_global.h"
#include <iostream>
#include <fstream>

enum class WaveForm { SINUSOID, SQUARE, RAMP, PULSE, NOISE, DC };
enum class Channel { CHANNEL1, CHANNEL2 };
enum class OutputState {ON, OFF};

class DG1022_EXPORT DG1022
{
public:
    DG1022(std::string device);
    ~DG1022();
    void setOutput(OutputState onOff, Channel chan = Channel::CHANNEL1);
    void setFrequency(float f, Channel chan = Channel::CHANNEL1);
    void setWaveForm(WaveForm f, Channel chan = Channel::CHANNEL1);
    void setVoltage(float v, Channel chan = Channel::CHANNEL1);
    void setPhase(float p, Channel chan = Channel::CHANNEL1);


private:
    void write(std::string line);
    std::string device;
    std::ofstream file;
};

#endif // DG1022_H
