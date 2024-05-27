/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:06:29 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 01:48:24 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	search_chr(char *string_input, char chr, char end)
{
	int	index;

	index = 0;
	while (string_input[index] && string_input[index] != end)
	{
		if (string_input[index] == chr)
			return (1);
		index++;
	}
	return (0);
}

void	return_error(t_global *gnl, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '>' && str[i + 1] == '>')
		gnl->error_msg = "near unexpected token '>>'";
	else if (str[i] == '>')
		gnl->error_msg = "near unexpected token '>'";
	else if (str[i] == '<' && str[i + 1] == '<')
		gnl->error_msg = "near unexpected token '<<'";
	else if (str[i] == '<')
		gnl->error_msg = "near unexpected token f '<'";
	if (str[i] == '|')
		gnl->error_msg = "near unexpected token `|'";
	gnl->valid_sntax = 0;
}

void	pipes_errors(t_global *info, char *input, int index)
{
	int	i;

	i = index - 1;
	while (i >= 0 && input[i] != '|')
	{
		if (input[i] == '<' || input[i] == '>')
		{
			info->error_msg = "near unexpected token `|'";
			info->valid_sntax = 0;
			return ;
		}
		if (spc_token(input[i]) == 0)
			return ;
		i--;
	}
	if (info->valid_sntax)
	{
		info->valid_sntax = 0;
		info->error_msg = "unexpected pipe token '|'";
		g_global.status_number = 258;
	}
	if (input[index] == '|' && !chr_token(input + (index) + 1))
		info->error_msg = "pipes are not closed properly";
}

void	errors_check(t_global *gnl, char *input)
{
	int	i;

	if (!input)
	{
		gnl->valid_sntax = 0;
		gnl->error_msg = "near unexpected token 'newline'";
		return ;
	}
	i = 0;
	while (input[i])
	{
		if (!spc_token(input[i]) && !token(input[i]))
			return ;
		if (token(input[i]))
		{
			return_error(gnl, input + i);
			return ;
		}
		i++;
	}
	gnl->valid_sntax = 0;
	gnl->error_msg = "near unexpected token `newline'";
}
