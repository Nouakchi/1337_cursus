/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:45:52 by onouakch          #+#    #+#             */
/*   Updated: 2023/08/12 04:48:22 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ITER_H__
# define __ITER_H__

# include <iostream>


template <class T, class U, class V>
void iter(T arr_adrss, U arr_len, V func)
{
    while (arr_len-- > 0)
        arr_adrss[arr_len] = func(arr_adrss[arr_len]);
}


# endif