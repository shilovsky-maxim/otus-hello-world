#define BOOST_TEST_MODULE tests

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(tests)

BOOST_AUTO_TEST_CASE(test_valid_build_number) {
    BOOST_CHECK(hw::buildNumber() > 0);
}

BOOST_AUTO_TEST_SUITE_END()