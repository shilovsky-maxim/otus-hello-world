#pragma once

#include <string>
#include <ostream>

namespace hw {
    unsigned int buildNumber();
    std::string welcomeString();
    void printWelcomeText(std::ostream& out);
}
