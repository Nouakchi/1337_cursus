/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:42:10 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:42:11 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "Utils.h"

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "few arguments !!\n";
        return (0);
    }

    std::string line;
    std::string filename;
    std::ifstream src_file (av[1]);

    
    if (src_file.is_open())
    {
        filename = av[1];
        std::ofstream new_file (  filename + ".replace");
        if (new_file.is_open())
        {
            while ( getline(src_file, line) )
                new_file << ftReplace(line, av[2], av[3]);
            src_file.close();
            new_file.close();
        }
        else
            std::cout << "Can't open file <" + filename + ".replace>\n";
    }
    else
        std::cout << "Can't open file <" + filename + ">\n";
    
    return (0);
}