

# include "RPN.hpp"

int main(int ac, char *av[])
{
    (void)av;
    if (ac != 2)
        return (std::cout << "Bad arguments !!\n", 0);
    RPN rpn;
    if (rpn.parseLine(av[1]))
        return (std::cout << "Error\n", 0);
    rpn.setSequence(av[1]);
    std::cout << rpn.calculate();
    return (0);
}