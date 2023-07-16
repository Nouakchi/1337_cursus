
# ifndef __SCALARCONVERTER_H__
# define __SCALARCONVERTER_h__

# include <iostream>

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter(/* args */);
    ScalarConverter( const ScalarConverter& copy );
    ~ScalarConverter();

    ScalarConverter& operator= ( const ScalarConverter& other );

    static void convert( char * );
    static bool isInt( char *);
    static bool isDouble( char *);
    static bool isFloat( char *);
};




# endif