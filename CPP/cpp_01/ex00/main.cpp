/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:38:47 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:38:48 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = NULL;
    zombie = zombie->newZombie( "foo" );
    zombie->randomChump("boo");
    delete zombie;
    return (0);
}