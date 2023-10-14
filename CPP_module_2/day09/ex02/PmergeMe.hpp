/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:25:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/14 16:26:21 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __PMERGEME_H__
# define __PMERGEME_H__

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>

class PmergeMe
{
    private:
        std::vector<size_t> main_chain;
        std::vector<size_t> pend;
        std::vector<size_t> combination_set;
        std::deque<size_t> d_main_chain;
        std::deque<size_t> d_pend;
        std::deque<size_t> d_combination_set;
        long strugller;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe( const PmergeMe& copy );

        PmergeMe &operator= ( const PmergeMe &other );

        std::vector<size_t>     &getMainchain();
        std::vector<size_t>     &getPend();
        std::vector<size_t>     &getCombination_set();
        std::deque<size_t>      &d_getMainchain();
        std::deque<size_t>      &d_getPend();
        std::deque<size_t>      &d_getCombination_set();
        void                    setStrugller( long val );
        void                    larger_of_two();
        void                    swapPairs( int first_p_idx, int second_p_idx, int flag );
        void                    sortPairs();
        void                    generate_combination();
        void                    fill_pend();
        void                    order_list();
        void                    d_larger_of_two();
        void                    d_swapPairs( int first_p_idx, int second_p_idx, int flag );
        void                    d_sortPairs();
        void                    d_generate_combination();
        void                    d_fill_pend();
        void                    d_order_list();
};

# endif