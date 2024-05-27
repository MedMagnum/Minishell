/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:29:02 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:52:05 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	close_pipes(int **pipes, int len)
{
	int	index;

	index = -1;
	while (++index < len && pipes[index])
	{
		close(pipes[index][0]);
		close(pipes[index][1]);
		free(pipes[index]);
	}
}

void	free_dop(t_op *head_ptr)
{
	if (!head_ptr)
		return ;
	free_dop(head_ptr->next);
	free(head_ptr->str);
	free(head_ptr);
}

void	free_dchar(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_commands(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_dchar(&cmd->cmd_string);
	free_dchar(&cmd->name_of_cmd);
	free_dchar(&cmd->infile);
	free_dchar(&cmd->outfile);
	free_dop(cmd->args);
	free_str_arr(cmd->argv);
	if (cmd->hdc_p[0] > 0)
		close(cmd->hdc_p[0]);
	if (cmd->hdc_p[1] > 0)
		close(cmd->hdc_p[1]);
	free_commands(cmd->next);
	free(cmd);
}

void	destory_data(t_global **generaldata)
{
	free_dop((*generaldata)->herdoc);
	(*generaldata)->herdoc = NULL;
	free_commands((*generaldata)->command_list);
	close_pipes((*generaldata)->p, (*generaldata)->cmd_count - 1);
	(*generaldata)->command_list = NULL;
	free((*generaldata)->p);
	free(*generaldata);
	*generaldata = NULL;
}
