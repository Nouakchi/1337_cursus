/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:39:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:39:07 by onouakch         ###   ########.fr       */
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

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    Zombie  *zombies;
    try
    {
        zombies = new Zombie[N];
        for (int i=0;i < N; i++)
            zombies[i].name = name;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (zombies);
}