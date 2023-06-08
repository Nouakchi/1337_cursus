/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:44 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/08 14:38:16 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point _point(2.99,1.5);
    Point pointa(1,1);
    Point pointb(3,2);
    Point pointc(3,1);
    
    std::cout << bsp(pointa, pointb, pointc, _point) << std::endl;
    
return 0;
}