/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:50:12 by hchowdhu          #+#    #+#             */
/*   Updated: 2024/12/11 20:58:52 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_lines(char *str)
{
	int		i;
	char	*allocated_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	allocated_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!allocated_str || !str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		allocated_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		allocated_str[i++] = '\n';
	allocated_str[i] = '\0';
	return (allocated_str);
}

char	*stock(char *str)
{
	int		i;
	int		j;
	char	*allocated_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str)
	{
		free(str);
		return (NULL);
	}
	allocated_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!allocated_str)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		allocated_str[j++] = str[i++];
	allocated_str[j] = '\0';
	free(str);
	return (allocated_str);
}

char	*read_and_append(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str), NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_and_append(fd, str);
	if (!str)
		return (NULL);
	line = get_lines(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = stock(str);
	return (line);
}
