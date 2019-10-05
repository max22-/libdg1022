#include <DG1022.h>
#include <fstream>
#include <chrono>
#include <thread>

DG1022::DG1022(std::string device)
{
    this->device = device;
    file.open(this->device, std::ios::in | std::ios::out);
}

DG1022::~DG1022() {
    std::cout << "Closing device " << device << std::endl;
    file.close();
}

void DG1022::setOutput(OutputState onOff, Channel chan) {
    switch (onOff) {
        case OutputState::ON:
            if(chan == Channel::CHANNEL1)
                write("OUTP ON");
            else if (chan == Channel::CHANNEL2)
                write("OUTP:CH2 ON");
            break;
        case OutputState::OFF:
            if(chan == Channel::CHANNEL1)
                write("OUTP ON");
            else if (chan == Channel::CHANNEL2)
                write("OUTP:CH2 ON");
            break;
    }
}

void DG1022::setFrequency(float f, Channel chan) {

}

void DG1022::setWaveForm(WaveForm f, Channel chan) {

}

void DG1022::setVoltage(float v, Channel chan) {

}

void DG1022::setPhase(float p, Channel chan) {

}

void DG1022::write(std::string line) {
    std::cout << "Writing..." << std::endl;
    file << line << std::endl;
    std::cout << line << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
