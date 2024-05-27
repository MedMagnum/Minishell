/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:01:41 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 05:11:21 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	ft_isdigit(char chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(char chr)
{
	if (chr >= 'a' && chr <= 'z')
		return (1);
	if (chr <= 'Z' && chr >= 'A')
		return (1);
	return (0);
}

void	len(long nbre, int *x)
{
	*x = 0;
	if (nbre < 0)
	{
		nbre = nbre * -1;
		*x = *x + 1;
	}
	while (nbre > 0)
	{
		nbre = nbre / 10;
		*x = *x + 1;
	}
	return ;
}

char	*allocate_and_protect(char *resulted_string, int *i, int nb)
{
	len(nb, i);
	resulted_string = malloc(*i + 1);
	if (!resulted_string)
		return (NULL);
	return (resulted_string);
}

char	*ft_itoa(int number)
{
	char	*resulted_string;
	long	nb;
	int		i;

	nb = number;
	resulted_string = allocate_and_protect(resulted_string, &i, nb);
	resulted_string[i--] = '\0';
	if (nb == 0)
	{
		resulted_string[0] = 48;
		return (resulted_string);
	}
	if (nb < 0)
	{
		resulted_string[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		resulted_string[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (resulted_string);
}
