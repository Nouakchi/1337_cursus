/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:03:49 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 15:04:03 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int fractional_bits = 8;

public:
    Fixed();
    Fixed(const Fixed &copy);
    ~Fixed();
    Fixed &operator = (const Fixed &copy);
    Fixed( const int value );
    Fixed( const double value );

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

};

# endif