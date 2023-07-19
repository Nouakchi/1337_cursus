/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:16:38 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/19 10:55:34 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

void check()
{
    system("leaks run");
}

int main()
{
    atexit(check);
    try
    {
        Array<int> a(4);
        
        unsigned int i = -1;
        while (++i < a.size())
            a[i] = i;
        std::cout << "-----------\n";
        Array<int> b(a);
        i = -1;
        while (++i < b.size())
            std::cout << b[i] << "\n";
        b[i - 1] = 200;
        std::cout << "-----------\n";
        Array<int> c;
        c = b;
        i = -1;
        while (++i < c.size())
            std::cout << c[i] << "\n";
        c[i - 1] = 100;
        std::cout << "-----------\n";
        std::cout << b[i - 1] << " != " << c[i - 1] << "\n";
        std::cout << "-----------\n";
        std::cout << a[-1] << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}