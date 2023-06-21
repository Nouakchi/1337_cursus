/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:49:37 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:58:44 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ICHARACTER_H__
# define __ICHARACTER_H__

#include <iostream>
#include "AMateria.hpp"

class AMateria;
class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip( AMateria* ) = 0;
    virtual void unequip( int idx ) = 0;
    virtual void use( int idx, ICharacter& target ) = 0;
};

# endif