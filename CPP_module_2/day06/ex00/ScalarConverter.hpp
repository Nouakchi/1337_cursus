
# ifndef __SCALARCONVERTER_H__
# define __SCALARCONVERTER_H__

# include <iostream>
# include <exception>
# include <iomanip>
# include <limits.h>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter( const ScalarConverter& copy );
    ~ScalarConverter();

    ScalarConverter& operator= ( const ScalarConverter& other );

    class BadArguments : public std::exception
    {
        public:
            const char* what() const throw();
    };

    static void convert( char * );

    static bool isInt( char * );
    static bool isDouble( char * );
    static bool isFloat( char * );
    static bool isLimit( char * );

    static void limitToFloat( char * );
    static void limitToDouble( char * );

    static void printChar( double );
    static void printInt( double );
    static void printDouble( double );
    static void printFloat( double );

};

# endif