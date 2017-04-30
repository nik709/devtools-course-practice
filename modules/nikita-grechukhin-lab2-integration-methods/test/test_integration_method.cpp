// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>

#include "include/integration_methods.h"

TEST(INTEGRATION_METHOD, q) {

    double value = 2.3;
    std::string function = "3*x + cos(2*x)";

    IntegrationMethod im;
    im.change_variable_to_value(function, value);

    std::string expected = "3*2.300000 + cos(2*2.300000)";	

    EXPECT_EQ(expected, function);
}