#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw BadArgument();
        std::string literal = av[1];
        if (!is_valid_input(literal))
            throw BadArgument();
        else
        {
            ScalarConverter::convert(literal);
        }
    }
    catch (BadArgument &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}