/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:45:04 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/07 16:48:21 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __MUTANTSTACK_H__
# define __MUTANTSTACK_H__

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    class iterator
    {
    private:
        typename std::deque<T>::iterator iter;
    
    public:
        iterator ( typename std::deque<T>::iterator _iter) : iter(_iter){}
        
        T& operator*() { return (*this->iter);}
        iterator& operator++() { ++iter; return (*this); }
        iterator& operator--() { --iter; return (*this); }
        iterator operator++(int) { iterator tmp = *this; ++iter; return (tmp); }
        bool operator== (const iterator& other) { return (this->iter == other.iter); }
        bool operator!= (const iterator& other) { return (!(this->iter == other.iter)); }
    };
    iterator rbegin() { return (iterator(this->c.begin())); }
    iterator end() { return (iterator(this->c.end())); }
};

class Iterator;

# include "MutantStack.tpp"

# endif