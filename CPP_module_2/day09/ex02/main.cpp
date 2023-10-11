
# include "PmergeMe.hpp"

void affiche( std::vector<size_t> list)
{
    std::vector<size_t>::iterator it;
    for(it=list.begin();it!=list.end();++it)
        std::cout << *it << " - ";
    std::cout << "\n";
}

void affiche_step2( std::vector<size_t> list)
{
    int i = -1;

    int list_len;

    i = 0;
    list_len = list.size();
    if (list_len % 2)
        list_len--;
    while (i < list_len)
    {
        std::cout << list[i] << " ";
        i += 2;
    }
    std::cout << "\n";
    i = 1;
    while (i < list_len)
    {
        std::cout << list[i] << " ";
        i += 2;
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
    // affiche(pm.getMainchain());
    // std::cout << "-------------\n";
    pm.larger_of_two();
    // affiche_step2(pm.getMainchain());
    // std::cout << "-------------\n";
    pm.sortPairs();
    // affiche_step2(pm.getMainchain());
    // std::cout << "-------------\n";
    pm.fill_pend();
    affiche(pm.getMainchain());
    std::cout << "-----\n";
    affiche(pm.getPend());
    std::cout << "-------------\n";
    affiche(pm.getCombination_set());
    std::cout << "-------------\n";
    // pm.order_list();
    // affiche(pm.getMainchain());
    return (0);
}