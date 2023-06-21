/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:35:05 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 09:55:20 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria( std::string const & type)
{
    this->type = type;
}

AMateria::AMateria( const AMateria &other ) : type(other.type)
{
    *this = other;
}

AMateria &AMateria::operator = ( const AMateria &other )
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use( ICharacter& target)
{
    
}