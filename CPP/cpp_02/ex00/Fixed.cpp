/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:02:40 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/05 15:02:41 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}