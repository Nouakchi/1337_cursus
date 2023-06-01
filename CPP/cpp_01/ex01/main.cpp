/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:39:02 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:39:04 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void check()
{
    system("leaks run");
}

int main()
{
    atexit(check);
    Zombie *zombies;

    zombies = NULL;
    zombies = zombies->zombieHorde(10, "foo");
    for(int i = 0; i < 4; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}