/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:36:14 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:08:50 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	spc_token(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}

int	chr_token(char *input_string)
{
	int	i;

	i = -1;
	while (input_string[++i])
	{
		if (!spc_token(input_string[i]) && input_string[i] != '|')
			return (1);
	}
	return (0);
}

int	infile_token(char c)
{
	if (c == '<')
		return (1);
	return (0);
}
