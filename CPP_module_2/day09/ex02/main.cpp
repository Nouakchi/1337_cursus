
# include "PmergeMe.hpp"

void affiche( std::vector<size_t> list , std::string msg )
{
    unsigned long i = -1;
    std::cout << msg;
    while (++i < list.size())
    {
        std::cout << " " << list[i];
        // if (i && list[i - 1] > list[i])
        // {
        //     std::cout << " not Sorted !!\n";
        //     return ;
        // }
    }
    // std::cout << "sorted !!\n";
    std::cout << "\n";
}

// void d_affiche( std::deque<size_t> list , std::string msg )
// {
//     unsigned long i = -1;
//     std::cout << msg;
//     while (++i < list.size())
//     {
//         std::cout << " " << list[i];
//         // if (i && list[i - 1] > list[i])
//         // {
//         //     std::cout << " not Sorted !!\n";
//         //     return ;
//         // }
//     }
//     // std::cout << "sorted !!\n";
//     std::cout << "\n";
// }


int main(int ac, char *av[])
{
    if (ac < 2)
        return (std::cout << "Few arguments !!\n", 0);
    PmergeMe pm;
    int i;

    i = 0;
    clock_t time = clock();
    std::cout << "Before: ";
    while (++i < ac)
    {
        std::cout << " " << av[i];
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
    time = static_cast<double>(clock() - time);
    affiche(pm.getMainchain(), "After: ");
    std::cout << "Time to process a range of " << pm.getMainchain().size() << " elements with std::vecotr<size_t> : " << time << " us" << std::endl;
    //
    i = 0;
    time = clock();
    while (++i < ac)
        pm.d_getMainchain().push_back(atoi(av[i]));
    // d_affiche(pm.d_getMainchain(), "Before: ");
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
    time = static_cast<double>(clock() - time);
    // d_affiche(pm.d_getMainchain(), "After: ");
    std::cout << "Time to process a range of " << pm.d_getMainchain().size() << " elements with std::deque<size_t> : " << time << " us" << std::endl;
    return (0);
}