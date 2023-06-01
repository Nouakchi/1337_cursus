/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:45:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:45:55 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __HARL_H__
# define __HARL_H__

#include <iostream>

class Harl
{
public:
    void complain( int index );

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

};

# endif