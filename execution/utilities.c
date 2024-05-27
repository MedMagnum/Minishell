/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:10:03 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:51:31 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	read_get_history(int fd, char *line)
{
	char	*tmp;

	tmp = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		add_history(line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
}

int	valid_indentifier(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (ft_isdigit(str[0]) || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] == '+' && !str[i + 1])
			return (1);
		if ((!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}

void	printerror(t_cmd *cmd)
{
	if (cmd->erno_fil)
	{
		ft_putstr_fd(cmd->erno_fil, 2);
		ft_putstr_fd(": ", 2);
	}
	if (cmd->error_type == 0)
		ft_putstr_fd("ambiguous error", 2);
	if (cmd->error_type > 0)
		ft_putstr_fd(strerror(cmd->error_type), 2);
	write(2, "\n", 1);
}

void	free_str_arr(char **str_arr)
{
	size_t	idx;

	idx = 0;
	if (!str_arr)
		return ;
	while (str_arr[idx])
	{
		free(str_arr[idx]);
		idx++;
	}
	free(str_arr);
}

int	catch_err(t_cmd *cmd, char **str)
{
	if (cmd->error_type >= 0)
	{
		printerror(cmd);
		g_global.status_number = 1;
		free_str_arr(str);
		return (1);
	}
	return (0);
}
