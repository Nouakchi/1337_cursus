
# ifndef __RPN_H__
# define __RPN_H__

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN
{
    private:
        std::stack<int> sequence;
    public:
        RPN();
        ~RPN();
        RPN( const RPN& copy );

        RPN &operator= ( const RPN& other );

        int                 parseLine( std::string seq );
        int                 calculate( std::string seq );
};

# endif

