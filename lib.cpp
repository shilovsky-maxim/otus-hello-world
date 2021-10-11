#include "lib.h"

#include "version.h"

namespace hw {
    unsigned int buildNumber() {
        return PROJECT_VERSION_PATCH;
    }

    std::string welcomeString() {
        return "Hello, World!";
    }

    void printWelcomeText(std::ostream& out) {
        out << "build " << buildNumber() << std::endl;
        out << welcomeString() << std::endl;
    }
}
