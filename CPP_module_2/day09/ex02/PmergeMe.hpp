
# ifndef __PMERGEME_H__
# define __PMERGEME_H__

# include <iostream>
# include <vector>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<size_t> main_chain;
        std::vector<size_t> pend;
        std::vector<size_t> combination_set;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe( const PmergeMe& copy );

        PmergeMe &operator= ( const PmergeMe &other );

        std::vector<size_t>    &getMainchain();
        std::vector<size_t>    &getPend();
        std::vector<size_t>    &getCombination_set();
        void    larger_of_two();
        void    swapPairs( int first_p_idx, int second_p_idx, int flag );
        void    sortPairs();
        void    generate_combination();
        void    fill_pend();
        void    order_list();
};

# endif