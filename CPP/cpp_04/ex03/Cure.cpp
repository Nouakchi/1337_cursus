/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:46:36 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/20 16:48:48 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() { this->type = "cure"; }

Cure::Cure(const Cure &other ){}

Cure::~Cure(){}

Cure &Cure::operator=(const Cure &other) { return (*this);}

Cure *Cure::clone() const { return (new Cure());}

void Cure::use( ICharacter & target )
{
    std::cout << "Cure: \"* heals " + target + "’s wounds *\"\n";
}