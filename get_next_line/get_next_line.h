/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:56:36 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/24 00:20:29 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h> 
# include<unistd.h> 
# include<fcntl.h> 
# include<stdlib.h> 

char	*ft_truncate_left(char *str);
char	*ft_truncate_right(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_check(char **reserve, char *res);
char	*ft_strdup(const char *s1);
#endif