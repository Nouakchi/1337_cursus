/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:44 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 16:14:29 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
Fixed a (5.5);
Fixed const b (5.5);
std::cout << "a=" << a << std::endl;
std::cout << "b=" << b << std::endl;
std::cout << "++a=" << ++a << std::endl;
std::cout << "a++=" << a++ << std::endl;
std::cout << "a=" << a << std::endl;
std::cout << "a=" << --a << std::endl;
std::cout << "a--=" << a-- << std::endl;
std::cout << "a=" << a << std::endl;
std::cout << "a + b=" << a + b << std::endl;
std::cout << "a - b=" << a - b << std::endl;
std::cout << "a * b=" << a * b << std::endl;
std::cout << "a / b=" << a / b << std::endl;
std::cout << "a < b=" << (a < b) << std::endl;
std::cout << "a <= b=" << (a <= b) << std::endl;
std::cout << "a > b=" << (a > b) << std::endl;
std::cout << "a >=b=" << (a >= b) << std::endl;
std::cout << "a == b=" << (a == b) << std::endl;
std::cout << "a != b=" << (a != b) << std::endl;
std::cout << "max(a , b)=" << Fixed::max( a, b ) << std::endl;
std::cout << "min(a, b)=" << Fixed::min( a, b ) << std::endl;

std::cout << "---------\n";

Fixed c;
Fixed const d( Fixed( 5.04f) );

std::cout << c << std::endl;
std::cout << ++c << std::endl;
std::cout << c << std::endl;
std::cout << c++ << std::endl;
std::cout << c << std::endl;
std::cout << d << std::endl;
std::cout << Fixed::max( c, d ) << std::endl;

return 0;
}