/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:38:38 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:38:41 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

#include <iostream>

class Zombie{
private:
    std::string name;

public:
    ~Zombie();

    void        announce( void );
    Zombie*     zombieHorde( int N, std::string name );

};

# endif