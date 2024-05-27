/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structures_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:56:11 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 01:57:18 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	infile(t_cmd *command, char *name)
{
	if (command->error_type < 0)
	{
		if (command->infile)
		{
			free(command->infile);
			command->infile = NULL;
		}
		close(command->read_from_fd);
		command->infile = name;
		command->read_from_fd = open(command->infile, O_RDONLY);
		if (command->read_from_fd < 0)
		{
			command->erno_fil = name;
			command->error_type = errno;
		}
		command->hdc = 0;
	}
	else
		free(name);
}

void	outfile(t_cmd *command_line, char *name)
{
	if (command_line->error_type < 0)
	{
		if (command_line->outfile)
		{
			free(command_line->outfile);
			command_line->outfile = NULL;
		}
		close(command_line->write_in_fd);
		command_line->outfile = name;
		if (command_line->out_mode == O_APPEND)
			command_line->write_in_fd = open(command_line->outfile,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			command_line->write_in_fd = open(command_line->outfile,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (command_line->write_in_fd < 0)
		{
			command_line->error_type = errno;
			command_line->erno_fil = name;
		}
	}
	else
		free(name);
}

void	args(t_cmd *cmd, char *argument)
{
	t_op	*new;

	new = create_op(argument);
	pb(&cmd->args, new);
}

void	cmd(t_cmd *cmd, char *the_name)
{
	cmd->name_of_cmd = the_name;
}

void	put_struct(char *str, int x, t_global *general, t_cmd *cmd_list)
{
	if (x == DOC || x == EXP_DOC)
		herdc(general, cmd_list, x, str);
	else if (x == IF)
		infile(cmd_list, str);
	else if (x == OF)
		outfile(cmd_list, str);
	else if (x == ARG)
		args(cmd_list, str);
	else if (x == CMD)
		cmd(cmd_list, str);
	return ;
}
