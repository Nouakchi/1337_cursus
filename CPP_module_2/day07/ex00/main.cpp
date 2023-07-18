/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:16:38 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/18 10:43:41 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void ) 
{
    int a = 2;
    int b = 3;
    Whatever::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << Whatever::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << Whatever::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    Whatever::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << Whatever::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << Whatever::max( c, d ) << std::endl;
    return 0;
}