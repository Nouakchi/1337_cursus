
# include "RPN.hpp"

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
    (void)seq;
    return (0);
}

int RPN::calculate()
{
    int result;

    result = 0;
    return (result);
}

