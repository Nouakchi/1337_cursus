/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:45:47 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 16:58:01 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void check()
{
    system("leaks run");
}

int main()
{
    atexit(check);
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout<<"----------\n\n";

j->getBrain()->ideas[0] = "j think => hello world\n";
i->getBrain()->ideas[0] = "i think => world hello\n";
std::cout << j->getBrain()->ideas[0] << i->getBrain()->ideas[0];

std::cout<<"----------\n\n";

Animal *k = new Dog();
*k = *j;
std::cout << k->getBrain()->ideas[0];
k->getBrain()->ideas[0] = "k pense => Bonjour tout le monde\n";
std::cout << j->getBrain()->ideas[0] << k->getBrain()->ideas[0];

std::cout<<"----------\n\n";
delete j;//should not create a leak
delete i;
delete k;
std::cout<<"----------\n\n";

// const Animal* animal = new Animal();
// animal->makeSound();
// delete animal;

// std::cout<<"----------\n\n";

return (0);
}