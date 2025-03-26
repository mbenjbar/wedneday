/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:10:02 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/26 00:11:37 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char *str, char c)
{
    int i = 0;
    char *result;

    if(!str){
        result = malloc(2);
        if(!result)
            return NULL;
        result[0] = c;
        result[1] = '\0';
        return result;
    }
    while (str[i])
    {
        i++;
    }
    result = malloc(i + 2);
    i = 0;
    while(str[i])
    {
        result[i] = str[i];
        i++;
    }
    result[i] = c;
    result[i+1] = '\0';
    free(str);
    return result;
}

char *get_next_line(int fd)
{
    static int bytes_read;
    static int buffer_pos;
    static char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    char c;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while(1)
    {
        if(buffer_pos >= bytes_read)
        {
            buffer_pos = 0;
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if(bytes_read <= 0)
                break;
        }
        c = buffer[buffer_pos++];
        line = ft_strjoin(line, c);
        if(!line)
            break;
        if(c == '\n')
            break;
    }
    if (line && *line)
        return line;
    else
        return NULL;
}
