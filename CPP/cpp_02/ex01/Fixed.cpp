/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:10 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 15:04:11 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->fixed_point = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed& copy)
{
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Fixed& Fixed::operator= (const Fixed& copy )
{
    std::cout << "Copy assignment operator called\n";
    this->fixed_point = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called\n";
    this->fixed_point = roundf(double(value) * pow(2, this->fractional_bits));
}

Fixed::Fixed( const double value )
{
    std::cout << "Float constructor called\n";
    this->fixed_point = roundf(value * pow(2, this->fractional_bits));
}

int Fixed::getRawBits() const
{
    return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
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
