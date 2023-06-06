/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:44 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/06 10:29:59 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point _point(5,1);
    Point pointa(0,0);
    Point pointb(4,0);
    Point pointc(2,3);
    
    std::cout << bsp(pointa, pointb, pointc, _point) << std::endl;
    
return 0;
}