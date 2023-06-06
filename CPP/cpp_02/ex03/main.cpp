/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:44 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 19:55:32 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point point(5,6);
    Point point2 = point;
    std::cout << point2.getX() << " / " << point2.getY();

return 0;
}