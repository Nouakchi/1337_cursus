/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:03:53 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/29 00:15:20 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strchr(const char *s, int c);
char	*ft_truncate_left(char *str);
char	*ft_truncate_right(char **str);
char	*ft_read_line(int fd, char *reserve);
char	*get_next_line(int fd);

#endif