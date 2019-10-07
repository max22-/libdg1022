#include <iostream>
#include <DG1022.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    DG1022 gen("/dev/usbtmc0");
    gen.setFrequency(440);
    gen.setOutputOn();
    gen.sleep(1000);
    gen.setOutputOff();
    return 0;
}
