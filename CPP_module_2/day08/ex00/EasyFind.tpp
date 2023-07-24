/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:04:26 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/21 16:40:00 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
int EasyFind::easyfind( T arr , int occ )
{
    unsigned long i = -1;
    
    while (++i < arr.size())
        if (arr[i] == occ)
            return occ;
    throw EasyFind::OccNotFound();
    return (-1);
};
