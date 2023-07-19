/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:27:22 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/19 10:59:06 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <class T>
Array<T>::Array()
{
    this->arr = new T();
    this->length = 0;
}

template <class T>
Array<T>::Array( unsigned int n )
{
    this->length = n;
    this->arr = new T[n]();
}

template <class T>
Array<T>::Array( const Array<T>& copy ) : arr(0)
{
    *this = copy;
}

template <class T>
Array<T>::~Array()
{
    delete []this->arr;
}

template <class T>
Array<T>& Array<T>::operator= ( const Array<T>& other )
{
    unsigned int i = -1;
    delete []this->arr;
    this->arr = new T[other.length]();
    while (++i < other.length)
        this->arr[i] = other.arr[i];
    this->length = other.length;
    return (*this);
}

template <class T>
const char *Array<T>::IndexOutOfRange::what() const throw()
{
    return ("Index is out of range !!\n");
}
    
template <class T>
T& Array<T>::operator[] (unsigned int index)
{
    if (index < 0 || index >= this->length )
        throw Array<T>::IndexOutOfRange();
    return (this->arr[index]);
}

template <class T>
unsigned int Array<T>::size() const
{
    return (this->length);
}
