/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:54:24 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 04:36:04 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	set_command(char *input, int *array, t_global *data, t_cmd **head)
{
	t_cmd	*list_cmd;

	if (input[array[0]] == '|')
		pipes_errors(data, input, array[0]);
	if (data->error_msg)
		return (0);
	list_cmd = cmd_add(*head);
	if (input[array[0] + 1] == '\0' && input[array[0]] != '|')
		list_cmd->cmd_string = get_line(input, array[1], array[0] + 1);
	else
		list_cmd->cmd_string = get_line(input, array[1], array[0]);
	add_cmd(head, list_cmd);
	array[1] = array[0] + 1;
	return (1);
}

int	find_the_close(char c, char *input)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (input[i] != '\0')
	{
		if (input[i] == c)
			ret = i;
		if (input[i] == c && (!input[i + 1] || spc_token(input[i + 1])
				|| input[i + 1] == '|'))
			break ;
		i++;
	}
	return (ret);
}

t_cmd	*fill_list(char *input, t_global *global_struct)
{
	t_cmd	*command_struct;
	int		array[2];

	command_struct = NULL;
	array[0] = -1;
	array[1] = 0;
	while (input[++array[0]])
	{
		if (input[array[0]] == '\'' || input[array[0]] == '\"')
		{
			if (input[array[0]] == '\'')
				array[0] += find_the_close('\'', input + array[0] + 1) + 1;
			else if (input[array[0]] == '\"')
				array[0] += find_the_close('\"', input + array[0] + 1) + 1;
		}
		if (input[array[0]] == '|' || input[array[0] + 1] == '\0')
		{
			if (!set_command(input, array, global_struct, &command_struct))
				break ;
		}
	}
	return (command_struct);
}
