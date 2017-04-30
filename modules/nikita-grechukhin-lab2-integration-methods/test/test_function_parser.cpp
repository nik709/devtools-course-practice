// Copyright 2017 Grechukhin Nikita 

#include <gtest/gtest.h> 
#include "include/function_parser.h"


TEST(EXPRESSION, can_create_expression_with_number_token) {
    std::string token = "1";

    Expression expression(token);

    EXPECT_EQ(token, expression.token);
}

TEST(EXPRESSION, can_create_expression_with_unary_operation) {
    std::string operation = "sin";
    Expression number("1");

    Expression expression(operation, number);

    EXPECT_EQ(operation, expression.token);
    EXPECT_EQ("1", expression.args.at(0).token);
}

TEST(EXPRESSION, can_create_expression_with_binary_operation) {
    std::string operation = "+";
    Expression number1("1");
    Expression number2("2");

    Expression expression(operation, number1, number2);

    EXPECT_EQ(operation, expression.token);
    EXPECT_EQ("1", expression.args.at(0).token);
    EXPECT_EQ("2", expression.args.at(1).token);
}

TEST(FUNCTION_PARSER, can_parse) {
    const char* token = "1+2*sin(45) + 5*(2+3)";
    Parser parser(token);
    double excepted = 1 + 2 * sin(45) + 5 * (2 + 3);

    EXPECT_EQ(excepted, eval(parser.parse()));
}

TEST(FUNCTION_PARSER, throw_exception_with_invalid_input) {
    const char* token = "";

    Parser parser(token);

    ASSERT_ANY_THROW(parser.parse());
}

TEST(FUNCTION_PARSER, throw_exception_with_invalid_brackets) {
    const char* token = "1+5*(1";

    Parser parser(token);

    ASSERT_ANY_THROW(parser.parse());
}
