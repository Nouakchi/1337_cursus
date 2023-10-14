/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:25:50 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/14 16:26:44 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

std::vector<size_t> &PmergeMe::getMainchain()
{
    return (this->main_chain);
}

std::vector<size_t> &PmergeMe::getPend()
{
    return (this->pend);
}

std::deque<size_t> &PmergeMe::d_getMainchain()
{
    return (this->d_main_chain);
}

std::deque<size_t> &PmergeMe::d_getPend()
{
    return (this->d_pend);
}


std::vector<size_t> &PmergeMe::getCombination_set()
{
    return (this->combination_set);
}

std::deque<size_t> &PmergeMe::d_getCombination_set()
{
    return (this->d_combination_set);
}

void    PmergeMe::setStrugller( long val )
{
    this->strugller = val;
}

void    PmergeMe::larger_of_two()
{
    size_t i;
    size_t main_chain_len;

    i = 1;
    main_chain_len = this->main_chain.size();
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

void    PmergeMe::d_larger_of_two()
{
    size_t i;
    size_t d_main_chain_len;

    i = 1;
    d_main_chain_len = this->d_main_chain.size();
    while (i < d_main_chain_len)
    {
        if (this->d_main_chain[i] > this->d_main_chain[i - 1])
        {
            int tmp = this->d_main_chain[i - 1];
            this->d_main_chain[i - 1] = this->d_main_chain[i];
            this->d_main_chain[i] = tmp;
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

void    PmergeMe::d_swapPairs( int first_p_idx, int second_p_idx, int flag )
{
    size_t f_tmp , s_tmp;

    f_tmp = this->d_main_chain[first_p_idx];
    this->d_main_chain[first_p_idx] = this->d_main_chain[second_p_idx];
    this->d_main_chain[second_p_idx] = f_tmp;
    if (flag)
    {
        s_tmp = this->d_main_chain[first_p_idx + 1];
        this->d_main_chain[first_p_idx + 1] = this->d_main_chain[second_p_idx + 1];
        this->d_main_chain[second_p_idx + 1] = s_tmp;
    }
}

void    PmergeMe::sortPairs()
{
    unsigned long i, j, min_idx, main_chain_len;

    i = 0;

    main_chain_len = this->main_chain.size();
    if (main_chain_len <= 3)
        return ;
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

void    PmergeMe::d_sortPairs()
{
    unsigned long i, j, min_idx, d_main_chain_len;

    i = 0;

    d_main_chain_len = this->d_main_chain.size();
    if (d_main_chain_len <= 3)
        return ;
    while (i < d_main_chain_len - 3)
    {
        j = i + 2;
        min_idx = i;
        while (j < d_main_chain_len - 1)
        {
            if (this->d_main_chain[min_idx] > this->d_main_chain[j])
                min_idx = j;
            j += 2;
        }
        if (min_idx != i)
            this->d_swapPairs(i, min_idx, 1);
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
    {
        jacobsthal_set.push_back(
            jacobsthal_set[i - 1] +
            (2 * (jacobsthal_set[i - 2]))
        );
    }
}

void    d_generate_jacobsthal( std::deque<size_t> &jacobsthal_set,  unsigned int size)
{
    unsigned long i;

    jacobsthal_set.push_back(1);
    jacobsthal_set.push_back(3);
    i = 1;
    while (++i <= size / 2)
    {
        jacobsthal_set.push_back(
            jacobsthal_set[i - 1] +
            (2 * (jacobsthal_set[i - 2]))
        );
    }
}

void    PmergeMe::generate_combination()
{
    unsigned long i, j;
    std::vector<size_t> jacobsthal_set;
    generate_jacobsthal( jacobsthal_set, this->main_chain.size());
    this->combination_set.push_back(3);
    this->combination_set.push_back(2);
    i = 1;
    while (++i < jacobsthal_set.size() && this->combination_set.size() <= this->pend.size())
    {
        j = jacobsthal_set[i];
        this->combination_set.push_back(j);
        while (--j > jacobsthal_set[i - 1])
            if (j <= this->pend.size() + 1)
                this->combination_set.push_back(j);
    }

}

void    PmergeMe::d_generate_combination()
{
    unsigned long i, j;
    std::deque<size_t> jacobsthal_set;
    d_generate_jacobsthal( jacobsthal_set, this->d_main_chain.size());
    this->d_combination_set.push_back(3);
    this->d_combination_set.push_back(2);
    i = 1;
    while (++i < jacobsthal_set.size() && this->d_combination_set.size() <= this->d_pend.size())
    {
        j = jacobsthal_set[i];
        this->d_combination_set.push_back(j);
        while (--j > jacobsthal_set[i - 1])
            if (j <= this->d_pend.size() + 1)
                this->d_combination_set.push_back(j);
    }

}

void    PmergeMe::fill_pend()
{
    unsigned long i = 1;
    while (i < this->main_chain.size())
    {
        this->pend.push_back(this->main_chain[i]);
        i += 2;
    }
    i = 0;
    while (++i < this->main_chain.size())
        this->main_chain.erase(this->main_chain.begin() + i);
    this->generate_combination();
    this->main_chain.insert(this->main_chain.begin(), this->pend[0]);
    this->pend.erase(this->pend.begin());
}

void    PmergeMe::d_fill_pend()
{
    unsigned long i = 1;
    while (i < this->d_main_chain.size())
    {
        this->d_pend.push_back(this->d_main_chain[i]);
        i += 2;
    }
    i = 0;
    while (++i < this->d_main_chain.size())
        this->d_main_chain.erase(this->d_main_chain.begin() + i);
    this->d_generate_combination();
    this->d_main_chain.insert(this->d_main_chain.begin(), this->d_pend[0]);
    this->d_pend.erase(this->d_pend.begin());
}

void    PmergeMe::order_list()
{
    unsigned long i, j;
    std::vector<size_t>::iterator pos;

    i = -1;
    j = -1;
    while (++i < this->pend.size())
    {
        while (this->combination_set[++j] > this->pend.size() + 1)
            ;
        pos = std::lower_bound(
                    this->main_chain.begin(),
                    this->main_chain.end(),
                    this->pend[this->combination_set[j] - 2]
                );
        this->main_chain.insert(
            this->main_chain.begin() + (pos - this->main_chain.begin()),
            this->pend[this->combination_set[j] - 2]
        );
    }
    if (this->strugller != -1)
    {
        pos = std::lower_bound(
                    this->main_chain.begin(),
                    this->main_chain.end(),
                    this->strugller
                );
        this->main_chain.insert(
            this->main_chain.begin() + (pos - this->main_chain.begin()),
            this->strugller
        );
        
    }
}

void    PmergeMe::d_order_list()
{
    unsigned long i, j;
    std::deque<size_t>::iterator pos;

    i = -1;
    j = -1;
    while (++i < this->d_pend.size())
    {
        while (this->d_combination_set[++j] > this->d_pend.size() + 1)
            ;
        pos = std::lower_bound(
                    this->d_main_chain.begin(),
                    this->d_main_chain.end(),
                    this->d_pend[this->d_combination_set[j] - 2]
                );
        this->d_main_chain.insert(
            this->d_main_chain.begin() + (pos - this->d_main_chain.begin()),
            this->d_pend[this->d_combination_set[j] - 2]
        );
    }
    if (this->strugller != -1)
    {
        pos = std::lower_bound(
                    this->d_main_chain.begin(),
                    this->d_main_chain.end(),
                    this->strugller
                );
        this->d_main_chain.insert(
            this->d_main_chain.begin() + (pos - this->d_main_chain.begin()),
            this->strugller
        );
    }
}