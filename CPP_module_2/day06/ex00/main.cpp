
#include <iostream>
#include "ScalarConverter.hpp"
#include <cstdlib>
int main(int ac, char *av[])
{
    try
    {
        if (ac == 2 && av[1][0] != '\0')
            ScalarConverter::convert(av[1]);
        else
            throw (ScalarConverter::BadArguments());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}