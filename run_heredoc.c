/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:12:23 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:12:53 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini.h"

t_cmd	*scrol_to_cmd(t_cmd *head, int x)
{
	while (head)
	{
		if (head->cmd_id == x)
			return (head);
		else
			head = head->next;
	}
	return (NULL);
}

char	*expanded_result(t_global *data, char *result)
{
	t_vars	*vars;
	char	*expanded;

	if (!result)
		return (NULL);
	vars = vars_expansion(result, data->env_list);
	expanded = final_result(vars, result);
	free_d(vars);
	return (expanded);
}

void	close_herdoc(t_global *general, t_op **herdoc_lim, char **result,
		char *str)
{
	t_cmd	*cmd;
	char	*ptr;

	cmd = scrol_to_cmd(general->command_list, (*herdoc_lim)->cmd_id);
	if (cmd && cmd->hdc \
		&& (!(*herdoc_lim)->next || (*herdoc_lim)->next->cmd_id != cmd->cmd_id))
	{
		if ((*herdoc_lim)->valid)
		{
			ptr = *result;
			*result = expanded_result(general, *result);
			free(ptr);
		}
		if (*result)
			write(cmd->hdc_p[1], *result, ft_strlen(*result));
		close(cmd->hdc_p[1]);
	}
	if (*result)
		free(*result);
	(*herdoc_lim) = (*herdoc_lim)->next;
	*result = NULL;
	if (str)
		free(str);
}

void	exit_status(t_global *data, t_op *del, char *input_string,
		char *resulted)
{
	t_cmd	*command;

	command = scrol_to_cmd(data->command_list, del->cmd_id);
	if (input_string)
		free(input_string);
	if (resulted)
		free(resulted);
	close(command->hdc_p[1]);
}

void	herdoc_execution(t_global *data_struct, t_op *del)
{
	char	*input_string;
	char	*resulted_string;

	resulted_string = NULL;
	sigint2();
	g_global.fd_new = dup(0);
	while (del)
	{
		g_global.get_nb = 1;
		input_string = readline(PT_D);
		if (g_global.get_nb == -1)
		{
			exit_status(data_struct, del, input_string, resulted_string);
			break ;
		}
		if (!input_string || !ft_strcmp(input_string, del->str))
			close_herdoc(data_struct, &del, &resulted_string, input_string);
		else
		{
			resulted_string = ft_strjoin_d(resulted_string, input_string);
			resulted_string = ft_strjoin_d(resulted_string, ft_strdup("\n"));
		}
	}
	dup2(g_global.fd_new, 0);
}
