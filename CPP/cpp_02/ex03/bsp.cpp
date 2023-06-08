/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:34:03 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/08 14:31:57 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(Point const a, Point const b, Point const c)
{
    float _a = a.getX() * (b.getY() - c.getY());
    float _b = b.getX() * (c.getY() - a.getY());
    float _c = c.getX() * (a.getY() - b.getY());
    return (abs((_a + _b + _c) / 2.0));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float t_area = area(a, b , c);
    float a_area = area(a, b , point);
    float b_area = area(b, c , point);
    float c_area = area(c, a , point);

    return ((a_area && b_area && c_area) && t_area == (a_area + b_area + c_area));
}