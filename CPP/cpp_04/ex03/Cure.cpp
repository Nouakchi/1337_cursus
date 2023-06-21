/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:46:36 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:06:03 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() { this->type = "cure"; }

Cure::Cure(const Cure &other ){ *this = other; }

Cure::~Cure(){}

Cure &Cure::operator=(const Cure &other) 
{
    if (this != &other)
        this->type = other.type;
     return (*this);
}

Cure *Cure::clone() const { return (new Cure(*this));}

void Cure::use( ICharacter & target )
{
    std::cout << "Cure: \"* heals " + target.getName() + "'s wounds *\"\n";
}