
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
        //     std::cout << "not Sorted !!\n";
        //     return ;
        // }
    }
    std::cout << "\n";
}


int main(int ac, char *av[])
{
    if (ac < 2)
        return (std::cout << "Few arguments !!\n", 0);
    PmergeMe pm;
    int i;

    i = 0;
    while (++i < ac)
        pm.getMainchain().push_back(atoi(av[i]));
    affiche(pm.getMainchain(), "Before: ");
    clock_t time;
    time = clock();
    pm.larger_of_two();
    pm.sortPairs();
    pm.fill_pend();
    pm.order_list();
    time = static_cast<double>(clock() - time);
    affiche(pm.getMainchain(), "After: ");
    std::cout << "Time to process a range of 3000 elements with std::vecotr<size_t> : " << time << std::endl;
    return (0);
}