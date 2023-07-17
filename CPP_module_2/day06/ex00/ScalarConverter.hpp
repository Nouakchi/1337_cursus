
# ifndef __SCALARCONVERTER_H__
# define __SCALARCONVERTER_H__

# include <iostream>
# include <exception>

class ScalarConverter
{
public:
    ScalarConverter(/* args */);
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
    
};




# endif