/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:59:28 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 07:21:41 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

long long	ft_atoi(const char *str)
{
	long						i;
	long						j;
	unsigned long long			k;

	i = 0;
	j = 1;
	k = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
			j = j * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (k * j);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c_dest;
	unsigned const char	*c_src;

	i = 0;
	c_dest = (unsigned char *)dst;
	c_src = (unsigned const char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dst);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != (char)c))
	{
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i] != '\0' && to_find[j] != '\0'
				&& str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start > len || start > ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}
