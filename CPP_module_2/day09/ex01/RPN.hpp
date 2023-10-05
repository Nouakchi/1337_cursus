
# ifndef __RPN_H__
# define __RPN_H__

# include <iostream>
# include <vector>

class RPN
{
    private:
        std::vector<char> sequence;
    public:
        RPN();
        ~RPN();
        RPN( const RPN& copy );

        RPN &operator= ( const RPN& other );

        std::vector<char>   getSequence();
        void                setSequence( std::string seq );
        int                 parseLine( std::string seq );
        int                 calculate();
};

# endif

