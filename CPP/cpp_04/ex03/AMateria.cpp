/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:35:05 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/20 16:16:07 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Materia's default contructor\n";
}

AMateria::AMateria( std::string const & type)
{
    this->type = type;
    std::cout << "Materia's Params contructor\n";
}

AMateria::AMateria( const AMateria &other ) : type(other.type)
{
    *this = other;
    std::cout << "Materia's copy constructor\n";
}

AMateria &AMateria::operator = ( const AMateria &other )
{
    this->type = other.type;
    std::cout << "Materia's copy assignement called\n";
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use( ICharacter& target)
{
    
}