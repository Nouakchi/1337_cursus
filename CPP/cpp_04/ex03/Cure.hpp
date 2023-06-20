/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:46:52 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/20 16:47:05 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __CURE_H__
# define __CURE_H__

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure( const Cure &other );
    ~Cure();

    Cure &operator = ( const Cure &other );
    Cure* clone() const;
    void use(ICharacter& target);
};

# endif