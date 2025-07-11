#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <regex.h>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    public:
        static void convert(std::string& input);
    private:
        ScalarConverter();
        static void convert_to_char(double& input, bool& isnan);
        static void convert_to_int(double& input, bool& isnan, bool& isinfp, bool& isinfn);
        static void convert_to_float(double& input, bool& isnan, bool& isinfp, bool& isinfn);
        static void convert_to_double(double& value, bool& isnan, bool& isinfp, bool& isinfn);
        ~ScalarConverter();
};

class BadArgument : public std::exception
{
    public:
        virtual char const* what() const throw();
};

bool is_valid_input(std::string& input);

#endif