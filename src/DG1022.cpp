#include <DG1022.h>
#include <fstream>
#include <chrono>
#include <thread>

DG1022::DG1022(std::string device) : dstream(device)
{
    this->device = device;
}

DG1022::~DG1022() {
    std::cout << "Closing device " << device << std::endl;
}

void DG1022::setOutputOn(Channel chan) {
    if(chan == Channel::CHANNEL1)
        dstream << "OUTP ON" << endl;
    else if (chan == Channel::CHANNEL2)
        dstream << "OUTP:CH2 ON" << endl;
}

void DG1022::setOutputOff(Channel chan) {
    if(chan == Channel::CHANNEL1)
        dstream << "OUTP OFF" << endl;
    else if (chan == Channel::CHANNEL2)
        dstream << "OUTP:CH2 OFF" << endl;
}

void DG1022::setFrequency(float f, Channel chan) {
    if(chan == Channel::CHANNEL1) {
        dstream << "FREQ " << f << endl;
    }
    else if (chan == Channel::CHANNEL2)
        dstream << "FREQ:CH2 " << f << endl;
}

void DG1022::setWaveForm(WaveForm f, Channel chan) {

}

void DG1022::setVoltage(float v, Channel chan) {

}

void DG1022::setPhase(float p, Channel chan) {

}

void DG1022::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
