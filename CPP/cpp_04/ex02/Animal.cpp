/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:45:52 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 16:08:31 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "";
    std::cout << "Animal Default constructor\n";
}

Animal::Animal( const Animal &copy )
{
    *this = copy;
    std::cout << "Animal copy Constructor\n";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor\n";
}

Animal &Animal::operator = ( const Animal &copy )
{
    this->type = copy.type;
    std::cout << "Animal copy assignement\n";
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}