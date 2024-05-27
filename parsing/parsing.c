/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:29:54 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:07:49 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

t_op	*create_op(char *str)
{
	t_op	*ptr;

	ptr = (t_op *)malloc(sizeof(t_op));
	if (ptr == 0)
		return (NULL);
	ptr->str = str;
	return (ptr);
}

void	herdc(t_global *data, t_cmd *cmd_list, int x, char *del)
{
	t_op	*ptr;

	if (cmd_list->read_from_fd > 0)
		close(cmd_list->read_from_fd);
	cmd_list->hdc = 1;
	ptr = create_op(del);
	ptr->str = del;
	ptr->valid = 0;
	if (x == EXP_DOC)
		ptr->valid = 1;
	cmd_list->read_from_fd = -1;
	ptr->cmd_id = cmd_list->cmd_id;
	pb(&data->herdoc, ptr);
}

t_global	*parsing(char *input, char **ev, t_env *env_list)
{
	t_global	*global_struct;

	global_struct = malloc(sizeof(t_global));
	if (!global_struct)
		return (NULL);
	global_struct->env = ev;
	global_struct->p = NULL;
	global_struct->herdoc = NULL;
	global_struct->valid_sntax = 1;
	global_struct->env_list = env_list;
	global_struct->error_msg = NULL;
	global_struct->command_list = fill_list(input, global_struct);
	command_line(global_struct);
	global_struct->cmd_count = id_command(global_struct->command_list);
	builted_or_not(global_struct->command_list);
	final_parse(global_struct);
	return (global_struct);
}
