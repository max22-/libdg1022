#include <iostream>
#include <DG1022.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    DG1022 gen("/dev/usbtmc0");
    gen.setOutputOn();
    return 0;
}
