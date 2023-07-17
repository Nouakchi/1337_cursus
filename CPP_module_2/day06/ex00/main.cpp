
#include <iostream>
#include "ScalarConverter.hpp"
#include <cstdlib>
int main(int ac, char *av[])
{
    if (ac == 2 && av[1][0] != '\0')
    {
        if (ScalarConverter::isFloat(av[1]) || ScalarConverter::isDouble(av[1])
                                            || ScalarConverter::isInt(av[1]))
        {
            double number = std::atof(av[1]);
            std::cout << "char: " ;
            if (number > 31 && number < 127)
                std::cout << "'" << static_cast<char>(number) << "'\n";
            else
                std::cout << "Non displayable\n";
            std::cout << "int: " << static_cast<int>(number) << "\n";
            std::cout << "float: " << static_cast<float>(number);
            if (static_cast<float>(number) == (int)number)
                std::cout << ".0";
            std::cout << "f\n";
            std::cout << "double: " << static_cast<double>(number);
            if (static_cast<double>(number) == (int)number)
                std::cout << ".0";
            std::cout << "\n";
        }
    }
    else
        std::cout << "Bad Arguments !!\n";
    // (void)ac;
    // (void)av;
    // int a = 42;
    // double b = 42.0;
    // float c = 42.0f;
    // (void)b;
    // if (a == c)
    //     std::cout << "yes\n";
    // else
    //     std::cout << "no\n";
    return (0);
}