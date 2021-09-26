#include <iostream>

#include "lib.h"

int main (int, char **)
{
    using namespace hw;
    std::cout << "build " << buildNumber() << std::endl;
    std::cout << welcomeString() << std::endl;
    return 0;
}