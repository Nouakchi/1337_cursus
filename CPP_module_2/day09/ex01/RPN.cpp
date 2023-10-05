
# include "RPN.hpp"
# include <string.h>

RPN::RPN() { }

RPN::~RPN() { }

RPN::RPN( const RPN& copy ) { (void) copy; }

RPN &RPN::operator= ( const RPN& other ) { (void) other; return (*this); }

int     RPN::parseLine( std::string seq )
{
    int i;
    int number_is_taken;
    int op_is_taken;

    i = -1;
    number_is_taken = 0;
    op_is_taken = 0;
    while (seq[++i])
    {
        if (seq[i] == ' ')
        {
            number_is_taken = 0;
            continue;
        }
        if (seq[i] < '0' || seq[i] > '9')
        {
            if (!strchr("+-/*", seq[i]))
                return (1);
            else if (op_is_taken)
                return (1);
            op_is_taken = 1;
            number_is_taken = 0;
        }
        else
        {
            if (number_is_taken)
                return (1);
            number_is_taken = 1;
            op_is_taken = 0;
        }
    }
    return (0);
}

void    RPN::setSequence( std::string seq )
{
    int i;

    i = -1;
    while (seq[++i])
    {
        if (seq[i] == ' ')
            continue;
        this->sequence.push_back(seq[i]);
    }
}

int RPN::calculate()
{
    int result;

    result = 0;
    return (result);
}

