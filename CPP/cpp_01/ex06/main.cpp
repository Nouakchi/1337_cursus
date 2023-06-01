/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:45:58 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:45:59 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main( int ac, char *av[] )
{
    Harl harl;
    std::string level;
    if (ac != 2)
        return (0);
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t index;

    index = -1;
    level = av[1];
    while (++index < levels->length() && levels[index].compare(level));
    switch (index)
    {
        case 0:
            harl.complain(0);
        case 1:
            harl.complain(1);
        case 2:
            harl.complain(2);
        case 3:
            harl.complain(3);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
    return (0);
}