/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:21:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/06 10:04:09 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __POINT_H__
# define __POINT_H__

#include <iostream>

class Point
{
private:
    const float x;
    const float y;
    
public:
    Point();
    Point( const float x, const float y );
    Point( const Point &point );
    Point &operator = ( const Point &point ) const;
    ~Point();
    float getX() const;
    float getY() const;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

# endif