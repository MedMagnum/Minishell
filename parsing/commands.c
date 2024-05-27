/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:02:57 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 01:47:32 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	lines_t_fill(char *line, int x, t_global *general, t_cmd *cmd_list)
{
	int		i;
	char	*exp;
	char	*final_exp;

	i = 0;
	while (spc_token(line[i]))
		i++;
	if (line[i] == '\'' || line[i] == '\"')
	{
		if (line[i] == '\"')
			exp = line_double(line + i);
		if (line[i] == '\'')
			exp = line_single(line + i);
	}
	else
		exp = gt_line(line + i);
	final_exp = the_expand(&x, exp, general, line + i);
	i += ft_strlen(exp);
	final_exp = final_expand(&x, exp, final_exp);
	if (x == N_AMB && cmd_list->error_type < 0)
		cmd_list->error_type = 0;
	put_struct(final_exp, x, general, cmd_list);
	return (i);
}

int	herdocument_parsing(t_cmd *cmd_list, t_global *general, char *str)
{
	int	i;
	int	ex;

	i = 0;
	ex = 0;
	while (str[i])
	{
		while (spc_token(str[i]))
			i++;
		if (herdoc_token(str, i) && ex)
			i += 2;
		else if (ex)
			break ;
		errors_check(general, str + i);
		if (general->error_msg)
			break ;
		i += lines_t_fill(str + i, DOC, general, cmd_list);
		ex = 1;
	}
	if (!str[0])
	{
		general->valid_sntax = 0;
		general->error_msg = "near unexpected token 'newline'";
	}
	return (i);
}

int	commandline(char *str, int i, t_cmd *cmd_list, t_global *general)
{
	if (herdoc_token(str, i))
		i += herdocument_parsing(cmd_list, general, str + i + 2) + 2;
	else if (append_token(str, i))
	{
		cmd_list->out_mode = O_APPEND;
		errors_check(general, str + i + 2);
		if (!general->error_msg)
			i += lines_t_fill(str + i + 2, OF, general, cmd_list) + 2;
	}
	else if ((infile_token(str[i]) || outfile_token(str[i]))
		&& !general->error_msg)
		in_or_out_file(general, cmd_list, str, &i);
	else if (!spc_token(str[i]) && !cmd_list->name_of_cmd)
		i += lines_t_fill(str + i, CMD, general, cmd_list);
	else if (!spc_token(str[i]))
		i += lines_t_fill(str + i, ARG, general, cmd_list);
	return (i);
}

void	exprs(t_global *general, char *line, t_cmd *command_list)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(line);
	while (line[i] != '\0' && general->valid_sntax && !general->error_msg)
	{
		i = commandline(line, i, command_list, general);
		if (!general->valid_sntax || general->error_msg)
			break ;
		while (spc_token(line[i]))
			i++;
	}
	command_list->argv = array_to_treate(command_list);
}

void	command_line(t_global *general)
{
	t_cmd	*cmds_head;

	cmds_head = general->command_list;
	general->valid_sntax = 1;
	while (cmds_head && general->valid_sntax)
	{
		cmds_head->blt = 0;
		cmds_head->hdc = 0;
		exprs(general, cmds_head->cmd_string, cmds_head);
		if (!general->valid_sntax)
			break ;
		cmds_head = cmds_head->next;
	}
}
