/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:13:41 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/21 17:04:36 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "EasyFind.hpp"
# include <vector>

int main()
{

    try
    {
        std::vector<int> numbers;
        
        numbers.push_back(1);
        numbers.push_back(-3);
        numbers.push_back(3);
        numbers.push_back(4);
        
        std::cout << EasyFind::easyfind(numbers, 4) << "\n";
        
        std::vector<char> word;
        
        word.push_back('a');
        word.push_back('b');
        word.push_back('c');
        word.push_back('d');
        
        std::cout << (char)EasyFind::easyfind(word, 'a') << "\n";
        
        std::cout << (char)EasyFind::easyfind(word, 'D') << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
    return (0);
}