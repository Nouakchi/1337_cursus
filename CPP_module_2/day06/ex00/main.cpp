
#include <iostream>
#include "ScalarConverter.hpp"
#include <cstdlib>
int main(int ac, char *av[])
{
    (void)ac;
    (void)av;
    char str[] = "13.37f";
    float x = static_cast<float>(std::atof(str));
    std::cout << x << std::endl;
    return (0);
}