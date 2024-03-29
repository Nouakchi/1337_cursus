/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:02:36 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/21 11:41:42 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("unknow") 
{
    int i = -1;
    while (++i < 4)
        this->materias[i] = NULL;
}

Character::Character( std::string _name ) : name(_name) 
{
    int i = -1;
    while (++i < 4)
        this->materias[i] = NULL;
}

Character::Character( const Character &other ) : name(other.name)
{
    int i = -1;
    while (++i < 4)
    {
        this->materias[i] = NULL;
        if (other.materias[i] != NULL)
            this->materias[i] = other.materias[i];
    }
}

Character &Character::operator= ( const Character &other )
{
    if (this != &other)
    {
        int i = -1;
        
        this->name = other.name;
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

Character::~Character()
{
    int i = -1;
    
    while (++i < 4)
    {
        if (this->materias[i])
            delete this->materias[i];
    }
}

std::string const & Character::getName() const {return (this->name); }

void Character::equip( AMateria* m)
{
    int i = -1;
    while(++i < 4)
    {
        if (!this->materias[i])
        {
            this->materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->materias[idx])
            this->materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->materias[idx])
            this->materias[idx]->use(target);
    }
}