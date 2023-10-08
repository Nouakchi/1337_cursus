
# include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe(){}


std::vector<size_t> &PmergeMe::getMainchain()
{
    return (this->main_chain);
}

std::vector<size_t> &PmergeMe::getPend()
{
    return (this->pend);
}


std::vector<size_t> &PmergeMe::getCombination_set()
{
    return (this->combination_set);
}

void    PmergeMe::larger_of_two()
{
    size_t i;
    size_t main_chain_len;

    i = 1;
    main_chain_len = this->main_chain.size();
    if (main_chain_len % 2)
        main_chain_len--;
    while (i < main_chain_len)
    {
        if (this->main_chain[i] > this->main_chain[i - 1])
        {
            int tmp = this->main_chain[i - 1];
            this->main_chain[i - 1] = this->main_chain[i];
            this->main_chain[i] = tmp;
        }
        i += 2;
    }
}
void    PmergeMe::swapPairs( int first_p_idx, int second_p_idx, int flag )
{
    size_t f_tmp , s_tmp;

    f_tmp = this->main_chain[first_p_idx];
    this->main_chain[first_p_idx] = this->main_chain[second_p_idx];
    this->main_chain[second_p_idx] = f_tmp;
    if (flag)
    {
        s_tmp = this->main_chain[first_p_idx + 1];
        this->main_chain[first_p_idx + 1] = this->main_chain[second_p_idx + 1];
        this->main_chain[second_p_idx + 1] = s_tmp;
    }
}

void    PmergeMe::sortPairs()
{
    unsigned long i, j, min_idx, main_chain_len;

    i = 0;

    main_chain_len = this->main_chain.size();
    if (main_chain_len % 2)
        main_chain_len--;
    while (i < main_chain_len - 3)
    {
        j = i + 2;
        min_idx = i;
        while (j < main_chain_len - 1)
        {
            if (this->main_chain[min_idx] > this->main_chain[j])
                min_idx = j;
            j += 2;
        }
        if (min_idx != i)
            this->swapPairs(i, min_idx, 1);
        i += 2;
    }
}

void    generate_jacobsthal( std::vector<size_t> &jacobsthal_set,  unsigned int size)
{
    unsigned long i;

    jacobsthal_set.push_back(1);
    jacobsthal_set.push_back(3);
    i = 1;
    while (++i <= size / 2)
        jacobsthal_set.push_back(
            jacobsthal_set[i - 1] +
            (2 * (jacobsthal_set[i - 2]))
        );
}

int     contains( size_t num, std::vector<size_t> main_chain )
{
    unsigned long i = -1;
    while (++i < main_chain.size())
        if (num == main_chain[i])
            return (1);
    return (0);
}

void    PmergeMe::generate_combination()
{
    unsigned long i, j;
    std::vector<size_t> jacobsthal_set;

    generate_jacobsthal( jacobsthal_set, this->main_chain.size());
    this->combination_set.push_back(jacobsthal_set[1]);
    this->combination_set.push_back(2);
    i = 1;
    while (++i < jacobsthal_set.size())
    {
        j = jacobsthal_set[i];
        this->combination_set.push_back(j);
        while (!contains( --j, this->combination_set ))
            this->combination_set.push_back(j);
    }
}

void    PmergeMe::fill_pend()
{
    unsigned long i = -1;
    while (++i < this->main_chain.size())
        if (i % 2)
            this->pend.push_back(this->main_chain[i]);
}