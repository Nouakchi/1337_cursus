/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:49:01 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/18 09:09:40 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"

int main()
{
    std::srand(time(NULL));
    
    Base *ptr = Utils::generate();
    Base &ref = *Utils::generate();
    
    Utils::identify(ptr);
    Utils::identify(ref);
    
    //-----------------------------

    Base *p = NULL;
    Base &r = *p;
    
    Utils::identify(p);
    Utils::identify(r);
    
    //-----------------------------
    
    Utils::identify(NULL);
    Utils::identify(NULL);
    
    //-----------------------------
    
    Base *ptb = new B;
    Base &rtb = *new C;
    
    Utils::identify(ptb);
    Utils::identify(rtb);

    return (0);
}