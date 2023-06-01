/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:43:13 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:43:14 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main( void )
{
    Harl harl;

    harl.complain("ERRORR");
    harl.complain("DEBUG");
    harl.complain("INFOO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    return (0);
}