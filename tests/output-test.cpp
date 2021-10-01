#define BOOST_TEST_MODULE output_test

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(output_test)

BOOST_AUTO_TEST_CASE(output_test) {
    std::stringstream out, expected;
    expected << "build " << hw::buildNumber() <<std::endl << "Hello, World!" << std::endl;
    hw::printWelcomeText(out);
    BOOST_CHECK_EQUAL(out.str(), expected.str());
}

BOOST_AUTO_TEST_SUITE_END()