/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:25:38 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:11:32 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    AMateria *materias[4];
    
    MateriaSource();
    MateriaSource( const MateriaSource &other );
    ~MateriaSource();

    MateriaSource &operator = ( const MateriaSource &other );

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};


