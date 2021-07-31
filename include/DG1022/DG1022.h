#ifndef DG1022_H
#define DG1022_H

#include <iostream>
#include <DG1022/devicestream.h>
#include <DG1022/enums.h>


class DG1022
{
public:
    DG1022(std::string device);
    ~DG1022();
    DG1022& setOutput(OutputState os, Channel chan = Channel::CHANNEL1);
    DG1022& setFrequency(float f, Channel chan = Channel::CHANNEL1);
    DG1022& setWaveForm(WaveForm wf, Channel chan = Channel::CHANNEL1);
    DG1022& setVoltage(float v, Channel chan = Channel::CHANNEL1);
    DG1022& setOffset(float o, Channel chan = Channel::CHANNEL1);
    DG1022& setPhase(float p, Channel chan = Channel::CHANNEL1);

    DG1022& sleep(int ms);

private:
    std::string device;
    DeviceStream dstream;
};

#endif // DG1022_H
