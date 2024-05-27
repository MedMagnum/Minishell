/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:04:05 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:44:27 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

char	*which(t_env **path, char *cmd)
{
	char	**dirs;
	t_env	*path_val;
	char	*cmd_path;
	int		i;

	if (!cmd)
		return (NULL);
	if (check_absolute_path(cmd))
		return (cmd);
	path_val = get_env_value(path, "PATH");
	path_err(path_val);
	dirs = ft_split(path_val->data_side, ':');
	i = -1;
	while (dirs[++i])
	{
		cmd_path = ft_strjoin(dirs[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free_str_arr(dirs);
			return (cmd_path);
		}
	}
	free_str_arr(dirs);
	return (NULL);
}

int	check_absolute_path(char *cmd)
{
	if ((cmd[0] == '/') && (access(cmd, X_OK) != 0))
		print_error(-1, "no such file or directory");
	if ((cmd[0] == '/' || cmd[0] == '.') && (access(cmd, X_OK) == 0))
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	print_error(int error_code, char *message)
{
	if (error_code < 0)
	{
		printf("%s\n", message);
		exit(127);
	}
	else if (error_code == 1)
	{
		printf("%s\n", message);
		exit(1);
	}
}

void	close_pipes_and_wait(t_global *data, t_cmd *tmp, int pid)
{
	int	i;

	i = 0;
	while (i < data->cmd_count - 1)
	{
		close(data->p[i][0]);
		close(data->p[i][1]);
		i++;
	}
	if (pid != -1)
	{
		if ((waitpid(pid, &tmp->status_nbr, 0)) < 0)
			perror("waitpid");
		if (WIFEXITED(tmp->status_nbr))
			g_global.status_number = WEXITSTATUS(tmp->status_nbr);
	}
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(tmp->status_nbr))
		g_global.status_number = WEXITSTATUS(tmp->status_nbr);
}
