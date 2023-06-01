/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:42:13 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/01 18:42:14 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Utils.h"

std::string ftReplace(std::string line, std::string s1, std::string s2)
{
    int i;
    std::string result;

    i = -1;
    while (line[++i])
    {
        if (line.length() - i >= s1.length())
        {
            if (line.substr(i, s1.length()) == s1)
            {
                result.append(s2);
                i += s1.length() - 1;
            }
            else
                result += line[i];
        }
        else
            result += line[i];
    }
    return (result += "\n");
}