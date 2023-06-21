/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:04:13 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 09:53:59 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __AMATERIA_H__
# define __AMATERIA_H__

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string type;
public: 
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &other );
    ~AMateria();
    
    AMateria &operator = ( const AMateria &other );
    
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

# endif