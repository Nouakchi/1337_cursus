/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:29:57 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/21 20:05:46 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

time_t parseDateTime(const char* datetimeString, const char* format)
{
    struct tm tmStruct;
    strptime(datetimeString, format, &tmStruct);
    return mktime(&tmStruct);
}

int main(int ac, char *av[])
{
    if (ac != 2)
        return( std::cout << "Error: could not open file.\n", 0);
    
    std::ifstream input_file;
    BitcoinExchange btc;
    std::string line;
    char            *key;
    double          value;
    
    input_file.open(av[1]);
    btc.setData("data.csv");
    
    if (!input_file.is_open())  
        return ( std::cout << "Error: could not open file.\n", 0);
    if (input_file.is_open())
    {
        getline(input_file, line);
        if (line != "date | value")
            std::cout << "Error: bad input => [data | value]" << std::endl;
        else
        {
            while (getline(input_file, line))
            {
                if (!BitcoinExchange::parseLine(line))
                    continue;
                key = strtok((char *)line.c_str(), " |");
                value = atof((const char*)strtok(NULL, " |"));
                
                time_t tm = parseDateTime(
                            (const char*)strcat(key, " 00:00:00"),
                            "%Y-%m-%d %H:%M:%S"
                        );
                
                btc.getDateValue(tm ,value);
            }
            input_file.close();
        }
    }
   
    return (0);
}