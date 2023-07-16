
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter& other )
{
    (void) other;
    return (*this);
}

void ScalarConverter::convert( char *input )
{
    (void)input;
}

bool ScalarConverter::isInt( char *input )
{
    int i = -1;
    while (input[++i])
        if (!std::isdigit(input[i]))
            return (false);
    return (true);
}

bool ScalarConverter::isDouble( char *input )
{
    int i = -1;
    int checked = 0;
    while(input[++i])
    {
        if (input[i] == '.' && !checked)
            checked = 1;
        else if (!std::isdigit(input[i]))
            return (false);
    }
    if (!checked || i == 1 )
        return (false);
    return (true);
}

bool ScalarConverter::isFloat( char *input )
{
    int i = -1;
    while (input[++i])
        ;
    if (input[i - 1] != 'f' && input[i - 1] != 'F')
        return (false);
    char buff[i];
    buff[i - 1] = '\0';
    int j = -1;
    while (++j < i - 1)
        buff[j] = input[j];
    if (!ScalarConverter::isDouble(buff))
        return (false);
    return (true);
}