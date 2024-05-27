/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:58:38 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 10:14:45 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 1

char	*ft_cut(char *stored)
{
	int		i;
	char	*str;

	i = 0;
	if (!stored[i])
		return (NULL);
	i = ft_sizelen(stored);
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
	{
		str[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_last_part(char *stored)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	i = ft_sizelen(stored);
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stored) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stored[i])
		str[j++] = stored[i++];
	str[j] = '\0';
	free(stored);
	return (str);
}

char	*read_join(int fd, char *buffer)
{
	char	*str;
	int		c;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	c = 1;
	while (c != 0 && !(ft_strchr(buffer, '\n')))
	{
		c = read(fd, str, BUFFER_SIZE);
		if (c < 0)
		{
			free(str);
			return (NULL);
		}
		str[c] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str_rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_rd = read_join(fd, str_rd);
	if (!str_rd)
		return (NULL);
	buffer = ft_cut(str_rd);
	str_rd = ft_last_part(str_rd);
	return (buffer);
}
