/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:03:14 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 15:03:21 by onouakch         ###   ########.fr       */
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

    int getRawBits( void ) const;
    void setRawBits( int const raw );

};

# endif