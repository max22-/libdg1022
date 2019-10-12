#include <iostream>
#include <DG1022.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    DG1022 gen("/dev/usbtmc0");
    gen.setFrequency(440)
        .setOutputOn()
        .sleep(1000)
        .setOutputOff();
    return 0;
}
