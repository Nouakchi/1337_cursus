/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:56:36 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/24 20:51:14 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h> 
# include<unistd.h> 
# include<fcntl.h> 
# include<stdlib.h> 

size_t	ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strchr(const char *s, int c);
char	*ft_truncate_left(char *str);
char	*ft_truncate_right(char **str);
char	*ft_check(char **reserve);
char	*get_next_line(int fd);

#endif