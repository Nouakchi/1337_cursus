/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:49:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/17 14:36:05 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer( const Serializer& copy ){ (void) copy; }

Serializer::~Serializer(){}

Serializer& Serializer::operator= (const Serializer& other ) { (void) other; return (*this);}

uintptr_t Serializer::serialize( Data* ptr )
{
    return (reinterpret_cast<uintptr_t> (ptr));
}

Data *Serializer::deserialize( uintptr_t raw )
{
    return (reinterpret_cast <Data*> (raw));
}