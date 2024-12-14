/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:50:16 by hchowdhu          #+#    #+#             */
/*   Updated: 2024/12/14 22:55:13 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "string.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

size_t	ft_strlen(char *str);
char	*extract_and_update(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*get_next_line(int fd);
char	*read_and_append(int fd, char *str);

#endif