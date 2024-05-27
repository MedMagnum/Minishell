/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:01:00 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 02:01:13 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	valid_variable(char *input_string)
{
	int	i;

	i = 0;
	if (ft_isdigit(input_string[i]))
		return (0);
	if (!ft_isalpha(input_string[i]) && input_string[i] != '_')
		return (0);
	return (1);
}

int	builted(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "env"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (1);
	if (!ft_strcmp(str, "cd"))
		return (1);
	if (!ft_strcmp(str, "export"))
		return (1);
	if (!ft_strcmp(str, "exit"))
		return (1);
	if (!ft_strcmp(str, "unset"))
		return (1);
	return (0);
}

void	builted_or_not(t_cmd *command_line)
{
	while (command_line)
	{
		if (builted(command_line->name_of_cmd))
			command_line->blt = 1;
		command_line = command_line->next;
	}
}
