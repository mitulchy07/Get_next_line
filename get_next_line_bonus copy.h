/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:49:59 by hchowdhu          #+#    #+#             */
/*   Updated: 2024/12/11 20:21:45 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "string.h"

size_t	ft_strlen(char *str);
char	*get_lines(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*stock(char	*str);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*read_and_append(int fd, char *str);

#endif