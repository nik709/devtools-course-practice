// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#include <string>

class IntegrationMethod {
 public:
    IntegrationMethod();
    static double rectangle_method(std::string input, double low_limit, double upper_limit, int number_of_partitions);
    

 private:
     void change_variable_to_value(std::string &input, double value);
};

#endif  // MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
