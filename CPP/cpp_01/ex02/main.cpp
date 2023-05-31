#include <iostream>

int main()
{

    std::string word = "HI THIS IS BRAIN";
    std::string *stringPTR = &word;
    std::string &stringREF = word;

    std::cout << &word << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << word << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";

    return (0);
}