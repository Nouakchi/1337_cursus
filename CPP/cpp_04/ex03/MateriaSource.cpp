/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:25:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:28:44 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    int i = -1;
    while (++i < 4)
        this->materias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &other )
{
    int i = -1;
    while (++i < 4)
    {
        this->materias[i] = NULL;
        if (other.materias[i] != NULL)
            this->materias[i] = other.materias[i];
    }
}

MateriaSource &MateriaSource::operator= ( const MateriaSource &other )
{
    if (this != &other)
    {
        int i = -1;

        while (++i < 4)
        {
            if (this->materias[i])
            {
                delete this->materias[i];
                this->materias[i] = NULL;
            }
            if (other.materias[i] != NULL)
                this->materias[i] = other.materias[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    int i = -1;
    
    while (++i < 4)
    {
        if (this->materias[i])
            delete this->materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    int i = -1;

    while (++i < 4)
    {
        if (!this->materias[i])
        {
            this->materias[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = -1;

    while (++i < 4)
    {
        if (this->materias[i]->getType() == type)
            return (this->materias[i]->clone());
    }
    return (0);
}