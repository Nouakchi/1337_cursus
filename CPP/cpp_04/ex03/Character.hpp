/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:54:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:57:05 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __CHARACTER_H__
# define __CHARACTER_H__

#include <iostream>
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *materias[4];
public:
    Character();
    Character( std::string name );
    Character( const Character &other );
    ~Character();
    
    Character &operator = ( const Character &other );
    
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

# endif