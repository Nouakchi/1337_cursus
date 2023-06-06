/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:22:00 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 20:06:09 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0) , y(0) {}

Point::Point( const float _x, const float _y ) : x(_x) , y(_y) {}

Point::Point( const Point &point ) : x(point.x) , y(point.y){}

// this may blow test it after
//
Point &Point::operator = (const Point &_point) const
{
    return (*(new Point(_point)));
}
//

Point::~Point(){}