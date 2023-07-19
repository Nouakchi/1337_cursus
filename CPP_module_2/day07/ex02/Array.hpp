/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:38:58 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/19 10:12:56 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ARRAY_H__
# define __ARRAY_H__

# include <iostream>

template <class T>
class Array
{
private:
    T *arr;
    unsigned int length;

public:
    Array();
    Array( unsigned int n );
    Array( const Array& copy );
    ~Array();
    
    Array& operator= ( const Array& other );
    
    
    class IndexOutOfRange : public std::exception
    {
        public:
            const char* what() const throw();
    };

    T& operator[] ( unsigned int index);
    
    unsigned int size() const;
};

# include "Array.tpp"

# endif