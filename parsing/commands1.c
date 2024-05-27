/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:04:39 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 01:47:57 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

t_cmd	*go_next(t_cmd *head)
{
	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	return (go_next(head->next));
}

void	add_cmd(t_cmd **cmd, t_cmd *to_add)
{
	t_cmd	*command_line;

	if (!(*cmd))
	{
		*cmd = to_add;
		to_add->prev = NULL;
	}
	else
	{
		command_line = go_next(*cmd);
		command_line->next = to_add;
		to_add->prev = command_line;
	}
	to_add->next = NULL;
}

char	*get_line(char *cmd, int a, int b)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((b - a) + 1);
	if (!ret)
		return (NULL);
	while (a < b)
	{
		ret[i] = cmd[a];
		a++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	id_command(t_cmd *head)
{
	if (!head)
		return (0);
	else
		return (1 + id_command(head->next));
}

t_cmd	*cmd_add(t_cmd *head)
{
	t_cmd	*ret;

	ret = malloc(sizeof(t_cmd));
	if (!ret)
		return (NULL);
	ret->args = NULL;
	ret->infile = NULL;
	ret->outfile = NULL;
	ret->error_msg_s = NULL;
	ret->argv = NULL;
	ret->create = O_CREAT;
	ret->name_of_cmd = NULL;
	ret->cmd_string = NULL;
	ret->blt = 0;
	ret->erno_fil = NULL;
	ret->error_type = -1;
	ret->write_in_fd = -1;
	ret->read_from_fd = -1;
	ret->cmd_id = id_command(head) + 1;
	return (ret);
}
