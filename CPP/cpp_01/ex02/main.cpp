/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:39:14 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:39:15 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{

    std::string word = "HI THIS IS BRAIN";
    std::string *stringPTR = &word;
    std::string &stringREF = word;

    std::cout << &word << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << word << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";

    return (0);
}