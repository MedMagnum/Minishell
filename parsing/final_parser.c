/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:58:50 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 01:59:41 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	what_to_do_d_p(t_global *final_data_resulted, t_cmd *cmd,
		int pipe_index)
{
	if (cmd->error_type < 0)
	{
		if (cmd->write_in_fd == -1)
		{
			if (pipe_index == final_data_resulted->cmd_count - 1)
				cmd->write_in_fd = 1;
			else
				cmd->write_in_fd = final_data_resulted->p[pipe_index][1];
		}
		if (cmd->read_from_fd == -1)
		{
			if (pipe_index == 0 && !cmd->hdc)
				cmd->read_from_fd = 0;
			else if (cmd->hdc)
			{
				pipe(cmd->hdc_p);
				cmd->read_from_fd = cmd->hdc_p[0];
			}
			else
				cmd->read_from_fd = final_data_resulted->p[pipe_index - 1][0];
		}
	}
}

void	final_parse(t_global *final_data_resulted)
{
	int		i;
	t_cmd	*cmd;

	if (final_data_resulted->error_msg)
		return ;
	final_data_resulted->p = (int **)malloc(final_data_resulted->cmd_count
			* sizeof(int *));
	final_data_resulted->p[final_data_resulted->cmd_count - 1] = NULL;
	cmd = final_data_resulted->command_list;
	i = -1;
	while (++i < final_data_resulted->cmd_count)
	{
		if (i < final_data_resulted->cmd_count - 1)
		{
			final_data_resulted->p[i] = (int *)malloc(2 * sizeof(int));
			pipe(final_data_resulted->p[i]);
		}
		what_to_do_d_p(final_data_resulted, cmd, i);
		cmd = cmd->next;
	}
}
