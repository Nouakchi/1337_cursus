/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:16:50 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/20 16:32:05 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ICE_H__
# define __ICE_H__

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice( const Ice &other );
    ~Ice();

    Ice &operator = ( const Ice &other );
    Ice* clone() const;
    void use(ICharacter& target);
};

# endif