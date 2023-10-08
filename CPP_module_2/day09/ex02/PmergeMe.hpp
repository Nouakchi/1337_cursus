
# ifndef __PMERGEME_H__
# define __PMERGEME_H__

# include <iostream>
# include <vector>

class PmergeMe
{
    private:
        std::vector<size_t> list;
        std::vector<size_t> jacobsthal_set;
        std::vector<size_t> combination_set;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe( const PmergeMe& copy );

        PmergeMe &operator= ( const PmergeMe &other );

        std::vector<size_t>    &getList();
        std::vector<size_t>    &getJacobsthal_set();
        std::vector<size_t>    &getCombination_set();
        void    larger_of_two();
        void    swapPairs( int first_p_idx, int second_p_idx, int flag );
        void    sortPairs();
        void    generate_jacobsthal();
        void    generate_combination();
};

# endif