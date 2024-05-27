/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 04:45:34 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 04:49:48 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	ft_strcmp(char *string1, char *string2)
{
	int	index;

	index = 0;
	while (string1[index] == string2[index] && \
		string1[index] != '\0' && string2[index] != '\0')
		index++;
	return (string1[index] - string2[index]);
}

char	*ft_strdup(char *string)
{
	int		i;
	char	*resulted_string;

	if (!string)
		return (NULL);
	resulted_string = (char *) malloc ((ft_strlen(string) + 1) * sizeof(char));
	if (!resulted_string)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(string))
		resulted_string[i] = string[i];
	resulted_string[i] = 0;
	return (resulted_string);
}

char	*ft_strjoin(char *string1, char *string2)
{
	char	*resulted_string;
	int		len;
	int		size_s1;
	int		i;
	int		j;

	if (!string1 && string2)
		return (ft_strdup(string2));
	else if (!string2 && string1)
		return (ft_strdup(string1));
	else if (!string1 && !string2)
		return (NULL);
	size_s1 = ft_strlen(string1);
	len = size_s1 + ft_strlen(string2);
	resulted_string = (char *) malloc ((len + 1) * sizeof(char));
	i = -1;
	while (++i < size_s1 && string1[i])
		resulted_string[i] = string1[i];
	j = 0;
	while (i < len && string2[j])
		resulted_string[i++] = string2[j++];
	resulted_string[i] = 0;
	return (resulted_string);
}

int	ft_strlen(const char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}
