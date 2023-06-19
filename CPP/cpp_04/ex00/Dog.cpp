/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:46:04 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 13:46:05 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog Deafault constructor\n";
}

Dog::Dog( const Dog &copy ) : Animal(copy)
{
    std::cout << "copy constructor for " + type + "\n";
}

Dog::~Dog()
{
    std::cout << "Destructor fro " + type + "\n";
}

Dog &Dog::operator = (const Dog &copy )
{
    this->type = copy.type;
    std::cout << "copy assignement for " + type + "\n";
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dogs d'ont meow\n";
}