/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:38:51 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:38:52 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*     Zombie::newZombie( std::string name )
{
    Zombie *zombie = new Zombie;
    zombie->name = name;
    return (zombie);
}
