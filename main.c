/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:27:34 by hchowdhu          #+#    #+#             */
/*   Updated: 2024/12/13 20:30:00 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int fd = open("test.txt", O_RDONLY);
    int fd1 = open("test1.txt", O_RDONLY);
    char *nextline = get_next_line(fd);
    char *nextline1 = get_next_line(fd1);

    if (fd == -1 || fd1 == -1)
    {
        perror("There is an error in opening file.");
        return 1;
    }

    while (1)
    {
        if (!nextline && !nextline1)
            break;

        if (nextline)
        {
            printf("File 1: %s\n", nextline);
            free(nextline);
            nextline = NULL;
            i++;
        }

        if (nextline1)
        {
            printf("File 2: %s\n", nextline1);
            free(nextline1);
            nextline1 = NULL;
            i++;
        }
    }

    close(fd);
    close(fd1);

    return 0;
}
