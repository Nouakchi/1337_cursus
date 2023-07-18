/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:43:21 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/18 09:19:42 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"

Utils::Utils(){}

Utils::Utils( const Utils& copy ){(void)copy;}

Utils::~Utils(){}

Utils& Utils::operator= ( const Utils& other ){ (void)other; return (*this); }

Base *Utils::generate()
{
    int rand = std::rand() % 3;
    Base *ptr=  NULL;
    switch (rand)
    {
    case 0:
        ptr = new A;
        break;
    case 1:
        ptr = new B;
        break;
    case 2:
        ptr = new C;
        break;
    default:
        ptr = NULL;
        break;
    }
    return (ptr);
}

void Utils::identify( Base *ptr )
{
    A *pa = dynamic_cast<A*> (ptr);
    B *pb = dynamic_cast<B*> (ptr);
    C *pc = dynamic_cast<C*> (ptr);
    
    if (pa != 0)
        std::cout << "A\n";
    else if (pb != 0)
        std::cout << "B\n";
    else if (pc != 0)
        std::cout << "C\n";
    else
        std::cout << "??\n";
}
#include <sstream>
void Utils::identify( Base &ref )
{
    std::ostringstream  check_ref;
    
    check_ref << &ref;
    if (check_ref.str() != "0x0")
    {
        try
        {
            A &pa = dynamic_cast<A&> (ref);
            std::cout << "A\n";
            (void)pa;
            return ;
        }
        catch(const std::exception& e)
        {
            (void)e;
        }
        try
        {
            B &pb = dynamic_cast<B&> (ref);
            std::cout << "B\n";
            (void)pb;
            return ;
        }
        catch(const std::exception& e)
        {
            (void)e;
        }
        try
        {
            C &pc = dynamic_cast<C&> (ref);
            std::cout << "C\n";
            (void)pc;
            return ;
        }
        catch(const std::exception& e)
        {
            (void)e;
        }
    }
    std::cout << "??\n";
}
