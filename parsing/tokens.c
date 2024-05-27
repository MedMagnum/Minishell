/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:35:39 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:08:32 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	outfile_token(char c)
{
	if (c == '>')
		return (1);
	else
		return (0);
}

int	append_token(char *str, int i)
{
	return (str[i] == '>' && str[i + 1] == '>');
}

int	herdoc_token(char *str, int i)
{
	return (str[i] == '<' && str[i + 1] == '<');
}

int	token(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

int	ft_isalnum(char c)
{
	if (ft_isalpha(c))
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}
