
# include "RPN.hpp"
# include <string.h>

RPN::RPN() { }

RPN::~RPN() { }

RPN::RPN( const RPN& copy ) { (void) copy; }

RPN &RPN::operator= ( const RPN& other ) { (void) other; return (*this); }

void    RPN::setSequence( std::string seq )
{
    (void)seq;
}

int     RPN::parseLine( std::string seq )
{
    int i;

    i = -1;
    while (seq[++i])
    {
        if (seq[i] == ' ')
            continue;
        if (seq[i] < '0' || seq[i] > '9')
        {
            if (!strchr("+-/*", seq[i]))
                return (1);
            if (i && strchr("+-/*", seq[i - 1]))
                return (1);
        }
    }
    return (0);
}

int RPN::calculate()
{
    int result;

    result = 0;
    return (result);
}

