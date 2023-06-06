/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:24 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 16:31:07 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->fixed_point = 0.0;
}

Fixed::Fixed( const Fixed& copy)
{
    *this = copy;
}

Fixed& Fixed::operator= (const Fixed& copy )
{
    this->fixed_point = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

Fixed::Fixed( const int value )
{
    this->fixed_point = roundf(double(value) * pow(2, this->fractional_bits));
}

Fixed::Fixed( const double value )
{
    this->fixed_point = roundf(value * pow(2, this->fractional_bits));
}

int Fixed::getRawBits() const
{
    return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = roundf(double(raw) * pow(2, this->fractional_bits));
}

float Fixed::toFloat() const
{
    return (double(this->fixed_point) / pow(2, this->fractional_bits));
}

int Fixed::toInt() const
{
    return int(double(this->fixed_point) / pow(2, this->fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

bool Fixed::operator > (const Fixed &copy) const
{
    return (this->fixed_point > copy.fixed_point);   
}

bool Fixed::operator >= (const Fixed &copy)
{
    return (this->fixed_point >= copy.fixed_point);   
}

bool Fixed::operator < (const Fixed &copy) const
{
    return (this->fixed_point < copy.fixed_point);   
}

bool Fixed::operator <= (const Fixed &copy)
{
    return (this->fixed_point <= copy.fixed_point);   
}

bool Fixed::operator == (const Fixed &copy)
{
    return (this->fixed_point == copy.fixed_point);   
}

bool Fixed::operator != (const Fixed &copy)
{
    return (this->fixed_point != copy.fixed_point);   
}

Fixed Fixed::operator + (const Fixed &copy)
{
    Fixed fixed(this->toFloat() + copy.toFloat());
    return (fixed);
}

Fixed Fixed::operator - (const Fixed &copy)
{
    Fixed fixed(this->toFloat() - copy.toFloat());
    return (fixed);
}

Fixed Fixed::operator * (const Fixed &copy)
{
    Fixed fixed(this->toFloat() * copy.toFloat());
    return (fixed);
}

Fixed Fixed::operator / (const Fixed &copy)
{
    Fixed fixed;
    fixed.fixed_point = this->fixed_point / copy.fixed_point;
    return (fixed);
}

Fixed &Fixed::operator++()
{
    ++(this->fixed_point);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed fixed;
    fixed.fixed_point = this->fixed_point;
    (this->fixed_point)++;
    return (fixed);
}
Fixed &Fixed::operator--()
{
    --(this->fixed_point);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed fixed;
    fixed.fixed_point = this->fixed_point;
    (this->fixed_point)--;
    return (fixed);
}

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
    return (ref1 > ref2) ? ref2 : ref1;
}

const Fixed &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
    return (ref1 > ref2) ? ref2 : ref1;
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
    return (ref1 < ref2) ? ref2 : ref1;
}

const Fixed &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
    return (ref1 < ref2) ? ref2 : ref1;
}

