#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

char const *BadArgument::what() const throw()
{
    return "bad argument" ;
}

bool reg_match (std::string& input, const char *pattern)
{
    regex_t regex;

    int result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result)
        std::cout << "couldnt compile" << std::endl;

    result = regexec(&regex, input.c_str(), 0, NULL, 0);
    regfree(&regex);
    if (!result)
        return true;
    return false;    
}

bool is_valid_input(std::string& input)
{
    const char *patterns[] = {"^.$", "^[-+]?[0-9]+$", "^[-+]?[0-9]*\\.?[0-9]+f$", "^[-+]?[0-9]*\\.?[0-9]+$", "^[-+]inf[f]?$", "^nan[f]?$"};
    return (reg_match(input, patterns[0]) 
    || reg_match(input, patterns[1]) 
    || reg_match(input, patterns[2])
    || reg_match(input, patterns[3])
    || reg_match(input, patterns[4])
    || reg_match(input, patterns[5]));
}

void ScalarConverter::convert_to_char(double& value, bool& isnan)
{
    std::cout << "char:";
    if (value < 0 || value > CHAR_MAX || isnan)
        std::cout << " impossible" << std::endl;
    else if (!isprint(static_cast<char>(value)))
        std::cout << " Non displayable" << std::endl;
    else  
        std::cout << " '" << static_cast<char> (value) << "'" << std::endl;
}

void ScalarConverter::convert_to_int(double& value, bool& isnan, bool& isinfp, bool& isinfn)
{
    std::cout << "int: ";
    if (isnan || isinfp || isinfn || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}


void ScalarConverter::convert_to_float(double& value, bool& isnan, bool& isinfp, bool& isinfn)
{
    std::cout << "float: ";
    if (value < std::numeric_limits<float>::min()
      || value > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else if (isnan)
        std::cout << value << "f" << std::endl;
    else if (isinfp)
        std::cout << "+inff" << std::endl;
    else if (isinfn)
        std::cout << "-inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) 
        << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::convert_to_double(double& value, bool& isnan, bool& isinfp, bool& isinfn)
{
    std::cout << "double: ";
    if (value < std::numeric_limits<double>::min()
      || value > std::numeric_limits<double>::max())
        std::cout << "impossible" << std::endl;
    else if (isnan)
        std::cout << value << std::endl;
    else if (isinfp)
        std::cout << "+inf" << std::endl;
    else if (isinfn)
        std::cout << "-inf" << std::endl;
    else
        std::cout << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string& input)
{
    double value;
    
    bool isnan = (input == "nan") || (input == "nanf");
    bool isinfp = (input == "+inf") || (input == "+inff");
    bool isinfn = (input == "-inf") || (input == "-inff");
    if (input.length() == 1 && !isdigit(input[0]))
        value = static_cast<double> (input[0]);
    else 
        value = strtod(input.c_str(), NULL);
    // if ((value < INT_MIN || value > INT_MAX) && (!isinfp && !isinfn))
    //     throw BadArgument();
    convert_to_char(value, isnan);
    convert_to_int(value, isnan, isinfp, isinfn);
    convert_to_float(value, isnan, isinfp, isinfn);
    convert_to_double(value, isnan, isinfp, isinfn);
}

ScalarConverter::~ScalarConverter()
{

}