/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:29:11 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:06:50 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	free_strs(char *first_string, char *second_string)
{
	if (second_string)
		free(second_string);
	if (first_string)
		free(first_string);
}

char	*line_single(char *string_input)
{
	int		i;
	char	*resulted_string;
	int		specifier;

	specifier = 0;
	i = 0;
	if (string_input[i] == '\'')
		i += 1;
	while (string_input[i])
	{
		if (string_input[i] == '\'')
			specifier = !specifier;
		if (string_input[i] == '\'' && (!string_input[i + 1]
				|| spc_token(string_input[i + 1])))
			break ;
		i++;
	}
	if (!string_input[i])
		resulted_string = get_line(string_input, 0, i);
	else
		resulted_string = get_line(string_input, 0, i + 1);
	return (resulted_string);
}

char	*line_double(char *string_input)
{
	int		i;
	char	*resulted_string;
	int		already;

	already = 0;
	i = 0;
	if (string_input[i] == '\"')
		i += 1;
	while (string_input[i])
	{
		if (string_input[i] == '\"')
			already = !already;
		if ((string_input[i] == '\"' && (spc_token(string_input[i + 1])
					|| !string_input[i + 1])))
			break ;
		i++;
	}
	if (!string_input[i])
		resulted_string = get_line(string_input, 0, i);
	else
		resulted_string = get_line(string_input, 0, i + 1);
	return (resulted_string);
}

char	*gt_line(char *input_string)
{
	int		i;
	char	*resulted_string;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	while (input_string[++i] != '\0')
	{
		if (input_string[i] == '\'' && !x)
			y = !y;
		if (input_string[i] == '\"' && !y)
			x = !x;
		if ((input_string[i] == '<' || input_string[i] == '>'
				|| input_string[i] == '|') && (!x && !y))
			break ;
		if (input_string[i] == ' ' && !x && !y)
			break ;
	}
	resulted_string = get_line(input_string, 0, i);
	return (resulted_string);
}
