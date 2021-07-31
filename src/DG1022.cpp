#include <DG1022/DG1022.h>
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

DG1022& DG1022::setOutput(OutputState os, Channel chan) {
    dstream << "OUTP" << chan << " " << os << endl;
    return *this;
}

DG1022& DG1022::setFrequency(float f, Channel chan) {
    dstream << "FREQ" << chan << " " << f << endl;
    return *this;
}

DG1022& DG1022::setWaveForm(WaveForm wf, Channel chan) {
    dstream << "FUNC" << chan << " " << wf << endl;
    return *this;
}

DG1022& DG1022::setVoltage(float v, Channel chan) {
    dstream << setprecision(3) << "VOLT" << chan << " " << v << endl;
    return *this;
}

DG1022& DG1022::setOffset(float o, Channel chan) {
    dstream << setprecision(3) << "VOLT:OFFS" << chan << " " << o << endl;
    return *this;
}

DG1022& DG1022::setPhase(float p, Channel chan) {
    dstream << setprecision(1) << "PHAS" << chan << " " << p << endl;
    return *this;
}

DG1022& DG1022::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    return *this;
}
