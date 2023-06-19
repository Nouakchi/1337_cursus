/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:46:04 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 19:01:08 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog's Brain is created calling ";
    std::cout << "Dog Default constructor\n";
}

Dog::Dog( const Dog &copy ) : Animal(copy)
{
    std::cout << "copy constructor for " + type + "\n";
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog's Brain is destroyed calling ";
    std::cout << "Destructor for " + type + "\n";
}

Dog &Dog::operator = ( const Animal &copy )
{
    this->brain = new Brain(*copy.getBrain());
    std::cout << "copy assignement for " + type + "\n";
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dogs d'ont meow\n";
}

Brain *Dog::getBrain() const
{
    return (this->brain);
}