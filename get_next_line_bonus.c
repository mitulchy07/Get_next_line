/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:49:55 by hchowdhu          #+#    #+#             */
/*   Updated: 2024/12/14 22:54:23 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*extract_and_update(char **str)
{
	char	*line;
	char	*remaining;
	int		i;

	i = 0;
	if (!str || !*str || !(*str)[0])
		return (NULL);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, *str, i);
	line[i] = '\0';
	if ((*str)[i])
		remaining = strdup(*str + i);
	else
		remaining = NULL;
	free(*str);
	*str = remaining;
	return (line);
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
			return (free(str), free(buff), NULL);
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(str), free(buff), NULL);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[2048];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 2048)
		return (NULL);
	str[fd] = read_and_append(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = extract_and_update(&str[fd]);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (line);
}
