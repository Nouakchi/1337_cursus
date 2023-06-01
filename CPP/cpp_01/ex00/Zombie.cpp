/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:38:57 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:38:58 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << this->name + "\n";
}

void Zombie::announce( void )
{
    std::cout << this->name + ":  BraiiiiiiinnnzzzZ...\n";
}