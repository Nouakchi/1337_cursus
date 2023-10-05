
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
            if (!i)
                return (1);
            if (!strchr("+-/*", seq[i]))
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
    if (!op_is_taken)
        return (1);
    return (0);
}

int RPN::calculate( std::string seq )
{
    int i, a, b;

    i = -1;
    while (seq[++i])
    {
        if (seq[i] == ' ')
            continue;
        if (seq[i] >= '0' && seq[i] <= '9')
            this->sequence.push(seq[i] - 48);
        else
        {
            if (this->sequence.size() <= 1)
            {
                std::cout << "Not valid RPN, each operator should have the correct number of operands, and the expression should be well-formed" << std::endl;
                exit(1);
            }
            b = this->sequence.top();
            this->sequence.pop();
            a = this->sequence.top();
            this->sequence.pop();
            if (seq[i] == '+')
                this->sequence.push(a + b);
            else if (seq[i] == '-')
                this->sequence.push(a - b);
            else if (seq[i] == '/' && b)
                this->sequence.push(a / b);
            else if (seq[i] == '*')
                this->sequence.push(a * b);
            else
            {
                std::cout << "Not valid operation (div / 0)" << std::endl;
                exit(1);
            }
        }
    }
    return (this->sequence.top());
}

