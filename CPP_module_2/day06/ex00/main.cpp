/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:48:50 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/17 13:48:50 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ScalarConverter.hpp"
#include <cstdlib>
int main(int ac, char *av[])
{
    try
    {
        if (ac == 2 && av[1][0] != '\0')
            ScalarConverter::convert(av[1]);
        else
            throw (ScalarConverter::BadArguments());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}