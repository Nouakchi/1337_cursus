/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:54:45 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/26 23:12:12 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"


Span::Span() : size(0)
{
}

Span::Span( unsigned int n ) : size(n)
{
}

Span::Span( const Span& copy )
{
    *this = copy;
}

Span::~Span()
{
}

Span& Span::operator= ( const Span& other )
{
    
    this->size = other.size;
    std::list<int>::const_iterator  it;
    this->arr.clear();
    it = other.arr.begin();
    while (it!=other.arr.end())
        this->arr.push_back(*(it++));
    return (*this);
}

const char* Span::FullSpan::what() const throw()
{
    return ("Span is FULL !!\n");
}

const char* Span::NoSpanFound::what() const throw()
{
    return ("No Span Can Be found !!\n");
}

void Span::addNumber( unsigned int n )
{
    if (this->size + 1 >= this->size)
        throw Span::FullSpan();
    this->size++;
    this->arr.push_back(n);
}

int Span::shortestSpan()
{
    int distance;
    if (this->arr.size() < 2)
        throw Span::NoSpanFound();
    this->arr.sort();
    std::list<int>::iterator it = this->arr.begin();
    distance = abs(*it - *(++it));
    while (it != this->arr.end())
    {
        int tmp = abs(*it - *(++it));
        if (distance > tmp)
            distance = tmp;
    }
    return (distance);
}

int Span::longestSpan()
{
    if (this->arr.size() < 2)
        throw Span::NoSpanFound();
    this->arr.sort();
    return (*(--this->arr.end()) - *this->arr.begin());
}

void Span::addManyNumbers()
{
    if (this->size < 1000000)
        throw Span::FullSpan();
    this->size = 1000000;
    int arr[this->size];
    std::iota(arr, arr + this->size, std::rand() % this->size);
    this->arr.assign(arr, arr + this->size);
}

void Span::printList()
{
    std::list<int>::const_iterator it;

    it = this->arr.begin();
    while (it != this->arr.end())
        std::cout << *it++ << "\n";
}