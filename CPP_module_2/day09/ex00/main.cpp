/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:29:57 by onouakch          #+#    #+#             */
/*   Updated: 2023/09/29 11:57:16 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        return( std::cout << "Error: could not open file.\n", 0);
    std::ifstream input_file;
    input_file.open(av[1]);
    // if (!input_file.is_open())  
    //     return ( std::cout << "Error: could not open file.\n", 0);
    // std::string line;
    // if (input_file.is_open())
    // {
    //     getline(input_file, line);
    //     if (line != "date | value")
    //         std::cout << "Error: bad input => [data | value]" << std::endl;
    //     while (getline(input_file, line))
    //     {
    //         BitcoinExchange::parseLine(line);
    //     }
    //     input_file.close();
    // }
    BitcoinExchange btc;
    btc.setData("data.csv");
    std::map<time_t,double>::iterator it;
    for (it=btc.data.begin(); it!=btc.data.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    // if (!BitcoinExchange::parseLine("2023-02-28 | +8"))
    //     return (0);
    return (0);
}