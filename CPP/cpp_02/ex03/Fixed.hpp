/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:37 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 15:04:41 by onouakch         ###   ########.fr       */
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

    bool operator > (const Fixed &copy) const;
    bool operator >= (const Fixed &copy) ;
    bool operator < (const Fixed &copy) const;
    bool operator <= (const Fixed &copy) ;
    bool operator == (const Fixed &copy) ;
    bool operator != (const Fixed &copy) ;

    Fixed operator + (const Fixed &copy);  
    Fixed operator - (const Fixed &copy);  
    Fixed operator * (const Fixed &copy);  
    Fixed operator / (const Fixed &copy);  

    Fixed &operator++(); // ++i
    Fixed &operator--(); // --i
    Fixed operator++(int); //i++
    Fixed operator--(int); //i--

    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

    static const Fixed &min(const Fixed &ref1, const Fixed &ref2);
    static const Fixed &max(const Fixed &ref1, const Fixed &ref2);
    static Fixed &min(Fixed &ref1, Fixed &ref2);
    static Fixed &max(Fixed &ref1, Fixed &ref2);

};

# endif