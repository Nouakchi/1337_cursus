/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:40:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:40:07 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->name = name;
}

void HumanB::attack()
{
    std::cout << this->name + " attacks with their " + this->weapon->getType() + "\n";
}

void HumanB::setWeapon( Weapon &Weapon )
{
    this->weapon = &Weapon;
}