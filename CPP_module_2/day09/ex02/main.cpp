
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
        pm.getList().push_back(atoi(av[i]));
    pm.generate_jacobsthal();
    affiche(pm.getJacobsthal_set());
    pm.generate_combination();
    affiche(pm.getCombination_set());
    // affiche(pm.getList());
    // pm.larger_of_two();
    // std::cout << "-------------\n";
    // affiche(pm.getList());
    // std::cout << "-------------\n";
    // affiche_step2(pm.getList());
    // std::cout << "-------------\n";
    // pm.sortPairs();
    // affiche_step2(pm.getList());
    // std::cout << "-------------\n";
    // affiche(pm.getList());
    // std::cout << "-------------\n";
    return (0);
}