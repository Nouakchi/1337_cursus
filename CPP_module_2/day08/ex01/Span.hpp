/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:53:53 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/22 22:27:32 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __SPAN_H__
# define __SPAN_H__

# include <iostream>
# include <algorithm>
# include <list>
# include <ctime> 
# include <numeric>

class Span
{
private:
    unsigned int size;
    std::list<int> arr;
public:
    Span();
    Span( const Span& copy );
    Span( unsigned int n );
    ~Span();
    
    Span& operator= ( const Span& other );
  
    class FullSpan : public std::exception
    {
        public:
            const char* what() const throw();
    };
    
    class NoSpanFound : public std::exception
    {
        public:
            const char* what() const throw();
    };

    void addNumber( unsigned int );
    int shortestSpan();
    int longestSpan();
    void addManyNumbers();
    void printList();
    
};


# endif