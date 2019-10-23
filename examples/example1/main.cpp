#include <iostream>
#include <DG1022.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    DG1022 gen("/dev/usbtmc0");
    gen.setFrequency(440)
        .setVoltage(4.5)
        .setPhase(45.1)
        .setOutput(OutputState::ON)
        .sleep(2000)
        .setOutput(OutputState::OFF)
        .setFrequency(880, Channel::CHANNEL2)
        .setWaveForm(WaveForm::SQUARE, Channel::CHANNEL2)
        .setOutput(OutputState::ON, Channel::CHANNEL2)
        .sleep(2000)
        .setOutput(OutputState::OFF, Channel::CHANNEL2);
    return 0;
}
