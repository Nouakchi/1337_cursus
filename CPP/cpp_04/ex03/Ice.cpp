/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:36 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:05:08 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() { this->type = "ice"; }

Ice::Ice(const Ice &other ){ *this = other; }

Ice::~Ice(){}

Ice &Ice::operator=(const Ice &other) 
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Ice *Ice::clone() const { return (new Ice(*this));}

void Ice::use( ICharacter & target )
{
    std::cout << "Ice: \"* shoots an ice bolt at " + target.getName() +" *\"\n";
}