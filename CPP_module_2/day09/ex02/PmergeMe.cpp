
# include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe(){}


std::vector<size_t> &PmergeMe::getList()
{
    return (this->list);
}

std::vector<size_t> &PmergeMe::getJacobsthal_set()
{
    return (this->jacobsthal_set);
}

std::vector<size_t> &PmergeMe::getCombination_set()
{
    return (this->combination_set);
}

void    PmergeMe::larger_of_two()
{
    size_t i;
    size_t list_len;

    i = 1;
    list_len = this->list.size();
    if (list_len % 2)
        list_len--;
    while (i < list_len)
    {
        if (this->list[i] > this->list[i - 1])
        {
            int tmp = this->list[i - 1];
            this->list[i - 1] = this->list[i];
            this->list[i] = tmp;
        }
        i += 2;
    }
}
void    PmergeMe::swapPairs( int first_p_idx, int second_p_idx, int flag )
{
    size_t f_tmp , s_tmp;

    f_tmp = this->list[first_p_idx];
    this->list[first_p_idx] = this->list[second_p_idx];
    this->list[second_p_idx] = f_tmp;
    if (flag)
    {
        s_tmp = this->list[first_p_idx + 1];
        this->list[first_p_idx + 1] = this->list[second_p_idx + 1];
        this->list[second_p_idx + 1] = s_tmp;
    }
}

void    PmergeMe::sortPairs()
{
    unsigned long i, j, min_idx, list_len;

    i = 0;

    list_len = this->list.size();
    if (list_len % 2)
        list_len--;
    while (i < list_len - 3)
    {
        j = i + 2;
        min_idx = i;
        while (j < list_len - 1)
        {
            if (this->list[min_idx] > this->list[j])
                min_idx = j;
            j += 2;
        }
        if (min_idx != i)
            this->swapPairs(i, min_idx, 1);
        i += 2;
    }
    this->swapPairs(0 , 1 , 0);
}

void    PmergeMe::generate_jacobsthal()
{
    unsigned long i;

    this->jacobsthal_set.push_back(1);
    this->jacobsthal_set.push_back(3);
    i = 1;
    while (++i <= this->list.size() / 2)
        this->jacobsthal_set.push_back(
            this->jacobsthal_set[i - 1] +
            (2 * (this->jacobsthal_set[i - 2]))
        );
}

int     contains( size_t num, std::vector<size_t> list )
{
    unsigned long i = -1;
    while (++i < list.size())
        if (num == list[i])
            return (1);
    return (0);
}

void    PmergeMe::generate_combination()
{
    unsigned long i, j;

    this->combination_set.push_back(this->getJacobsthal_set()[1]);
    this->combination_set.push_back(2);
    i = 1;
    while (++i < this->getJacobsthal_set().size())
    {
        j = this->getJacobsthal_set()[i];
        this->combination_set.push_back(j);
        while (!contains( --j, this->combination_set ))
            this->combination_set.push_back(j);
    }
}