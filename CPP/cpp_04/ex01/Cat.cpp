/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:45:59 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 18:53:29 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat's Brain is created calling ";
    std::cout << "Cat Default constructor\n";
}

Cat::Cat( const Cat &copy ) : Animal(copy)
{
    std::cout << "copy constructor for " + type + "\n";
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat's Brain is destroyed calling ";
    std::cout << "Destructor for " + type + "\n";
}

Cat &Cat::operator = ( const Animal &copy )
{
    this->brain = copy.getBrain();
    std::cout << "copy assignement for " + type + "\n";
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "cats d'ont bark\n";
}

Brain *Cat::getBrain() const
{
    return (this->brain);
}