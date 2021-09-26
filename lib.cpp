#include "lib.h"

#include "version.h"

namespace hw {
    unsigned int buildNumber() {
        return PROJECT_VERSION_PATCH;
    }

    std::string welcomeString() {
        return "Hello, World!";
    }
}