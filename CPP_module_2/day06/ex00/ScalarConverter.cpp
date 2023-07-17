
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

const char* ScalarConverter::BadArguments::what() const throw()
{
    return ("Bad Arguments !!\n");
}

bool ScalarConverter::isInt( char *input )
{
    int i = -1;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (input[++i])
        if (!std::isdigit(input[i]))
            return (false);
    return (true);
}

bool ScalarConverter::isDouble( char *input )
{
    int i = -1;
    int checked = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;
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
    int i = std::strlen(input);
    if (input[i - 1] != 'f' && input[i - 1] != 'F')
        return (false);
    char buff[i];
    buff[i - 1] = '\0';
    int j = -1;
    if (input[0] == '-' || input[0] == '+')
        j++;
    while (++j < i - 1)
        buff[j] = input[j];
    if (!ScalarConverter::isDouble(buff))
        return (false);
    return (true);
}

bool ScalarConverter::isLimit( char *input )
{
    if (std::strcmp(input, "-inf") && std::strcmp(input, "+inf") && std::strcmp(input, "nan") &&
        std::strcmp(input, "-inff") && std::strcmp(input, "+inff") && std::strcmp(input, "nanf"))
        return (false);
    return (true);
}

void ScalarConverter::limitToDouble( char *input )
{
    int i = std::strlen(input);
    if (input[i - 2] == 'f' || !std::strcmp(input, "nanf"))
        input[i - 1] = '\0';
    std::cout << input << "\n";
} 

void ScalarConverter::limitToFloat( char *input )
{
    int i = std::strlen(input);
    std::cout << input;
    if (input[i - 2] != 'f' && std::strcmp(input, "nanf"))
        std::cout << "f";
    std::cout << "\n";
}

void ScalarConverter::printChar( double number )
{
    std::cout << "char: " ;
    if (number > 31 && number < 127)
        std::cout << "'" << static_cast<char>(number) << "'\n";
    else if ((number >= 0 && number <= 31) || number == 127)
        std::cout << "Non displayable\n";
    else
        std::cout << "impossible\n";
}

void ScalarConverter::printInt( double number )
{
    if (number <= std::numeric_limits<int>::max() && number >= std::numeric_limits<int>::lowest())
        std::cout << "int: " << static_cast<int>(number) << "\n";
    else
        std::cout << "int: impossible\n";
}

void ScalarConverter::printFloat( double number )
{
    if (number <= std::numeric_limits<float>::max() && number >= std::numeric_limits<float>::lowest())
    {
        std::cout << "float: " << std::setprecision(7) << static_cast<float>(number);
        if (static_cast<float>(number) == (int)number)
            std::cout << ".0";
        std::cout << "f\n";
    }
    else
        std::cout << "float: impossible\n";
}

void ScalarConverter::printDouble( double number )
{
    if (number <= std::numeric_limits<double>::max() && number >= std::numeric_limits<double>::lowest())
    {
        std::cout << "double: " << std::setprecision(15) << static_cast<double>(number);
        if (static_cast<double>(number) == (int)number)
            std::cout << ".0";
        std::cout << "\n";
    }
    else
        std::cout << "double: impossible\n";
}

void ScalarConverter::convert( char *input )
{
    //cehck this test ./convert -1 !!
    if (ScalarConverter::isFloat(input) || ScalarConverter::isDouble(input)
                                        || ScalarConverter::isInt(input))
    {
        double number = std::atof(input);
        ScalarConverter::printChar( number );
        ScalarConverter::printInt( number );
        ScalarConverter::printFloat( number );
        ScalarConverter::printDouble( number );
    }
    else if (ScalarConverter::isLimit(input))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: ";
        ScalarConverter::limitToFloat(input);
        std::cout << "double: ";
        ScalarConverter::limitToDouble(input);
    }
    else
        throw (ScalarConverter::BadArguments());
}