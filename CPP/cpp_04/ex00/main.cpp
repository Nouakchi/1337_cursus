
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "-------\n";

    const WrongAnimal *wanimal = new WrongAnimal();
    const WrongAnimal *wcat = new WrongCat();

    wcat->makeSound();
    wanimal->makeSound();


    return (0);
}