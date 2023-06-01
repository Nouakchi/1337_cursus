/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:40:53 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:40:54 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon( std::string type )
{
    this->type = type;
}

const std::string & Weapon::getType()
{
    return (this->type);
}

void Weapon::setType( std::string type )
{
    this->type = type;
}
