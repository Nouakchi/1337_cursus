/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:25:43 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/14 17:16:34 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

void affiche( std::vector<size_t> list , std::string msg )
{
    unsigned long i = -1;
    std::cout << msg;
    while (++i < list.size())
        std::cout << " " << list[i];
    std::cout << "\n";
}

void is_numeric( int ac, char **val )
{
    int i, j;

    i = 0;
    while (++i < ac)
    {
        j = -1;
        while (val[i][++j])
        {
            if (!j && val[i][j] == '+' && strlen(val[i]) > 1)
                j++;
            if (val[i][j] < '0' || val[i][j] > '9')
                return (std::cout << "Error\n" , exit(1));
        }
    }
}

void    sort_with_vector( PmergeMe &pm , int ac, char **av )
{
    int i;

    i = 0;
    std::cout << "Before: ";
    while (++i < ac)
    {
        std::cout << " " << atoi(av[i]);
        pm.getMainchain().push_back(atoi(av[i]));
    }
    std::cout << "\n";
    if (pm.getMainchain().size() != 1)
    {
        pm.setStrugller( -1 );
        if (pm.getMainchain().size() % 2)
        {
            pm.setStrugller( pm.getMainchain()[pm.getMainchain().size() - 1] );
            pm.getMainchain().pop_back();
        }
        pm.larger_of_two();
        pm.sortPairs();
        pm.fill_pend();
        pm.order_list();
    }
}

void    sort_with_deque( PmergeMe &pm , int ac, char **av )
{
    int i;

    i = 0;
    while (++i < ac)
        pm.d_getMainchain().push_back(atoi(av[i]));
    if (pm.d_getMainchain().size() != 1)
    {
        pm.setStrugller( -1 );
        if (pm.d_getMainchain().size() % 2)
        {
            pm.setStrugller( pm.d_getMainchain()[pm.d_getMainchain().size() - 1] );
            pm.d_getMainchain().pop_back();
        }
        pm.d_larger_of_two();
        pm.d_sortPairs();
        pm.d_fill_pend();
        pm.d_order_list();
    }
}


int main(int ac, char *av[])
{
    PmergeMe pm;
    
    if (ac < 2)
        return (std::cout << "Few arguments !!\n", 0);
    is_numeric(ac, av);
    clock_t time = clock();
    sort_with_vector(pm, ac, av);
    time = static_cast<double>(clock() - time);
    affiche(pm.getMainchain(), "After: ");
    std::cout << "Time to process a range of " << pm.getMainchain().size() << " elements with std::vecotr<size_t> : " << time << " us" << std::endl;
    //
    time = clock();
    sort_with_deque(pm, ac, av);
    time = static_cast<double>(clock() - time);
    std::cout << "Time to process a range of " << pm.d_getMainchain().size() << " elements with std::deque<size_t> : " << time << " us" << std::endl;
    return (0);
}