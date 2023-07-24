/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:58:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/21 16:40:21 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __EASYFIND_H__
# define __EASYFIND_H__

# include <iostream>

class EasyFind
{
public:
    EasyFind();
    EasyFind( const EasyFind& copy );
    ~EasyFind();
    
    EasyFind& operator= ( const EasyFind& other );
    
    template <class T>
    static int easyfind( T arr, int occ );
    
    class OccNotFound : public std::exception
    {
        public:
            const char* what() const throw()
            {
                return ("Occurence not found !!\n");
            }
    };
    
};

# include "EasyFind.tpp"

# endif