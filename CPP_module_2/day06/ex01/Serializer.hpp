/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:49:26 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/17 14:30:48 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __SERIALIZER_H__
# define __SERIALIZER_H__

# include <iostream>
# include "Data.h"

class Serializer
{
public:
    Serializer();
    Serializer(const Serializer& copy );
    ~Serializer();
    
    Serializer& operator= ( const Serializer& other );

    static uintptr_t   serialize(Data* ptr);
    static Data*       deserialize(uintptr_t raw);
    
};

# endif