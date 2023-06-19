/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:52:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 14:51:08 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __BRAIN_H__
# define __BRAIN_H__

#include <iostream>

class Brain
{
public:
    std::string ideas[100];

    Brain();
    Brain( const Brain &copy );
    ~Brain();

    Brain &operator = ( const Brain &copy );
};

# endif