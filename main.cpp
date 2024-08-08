#include <iostream>
// #include "adder.h"
#include <OLASConfig.h>

int main(int argc, char* argv[])
{
    std::cout << "Hello Sampath" << std::endl;

    #ifdef USE_ADDER
        std::cout << add(72.1f, 5.8f) << std::endl;
    #else
        std::cout << "Adder Lib Not adder" << std::endl;
    #endif

    std::cout << argv[0] << " Version " << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << std::endl;
    return 0;
}