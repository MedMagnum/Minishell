/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main_task.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:03:00 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 07:48:20 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	get_err(char *err, int is_exit)
{
	int	j;

	j = -1;
	while (COLOR_PRM[++j])
		write(2, &COLOR_PRM[j], 1);
	j = -1;
	while (ERR[++j])
		write(2, &ERR[j], 1);
	j = -1;
	while (RED_IN[++j])
		write(2, &RED_IN[j], 1);
	j = -1;
	while (err[++j])
		write(2, &err[j], 1);
	j = -1;
	while (RED_OUT[++j])
		write(2, &RED_OUT[j], 1);
	write(2, "\n", 1);
	if (is_exit)
		exit(EXIT_FAILURE);
}

void	parsing_executing_cmd(t_env **env_v, char *s, char **env)
{
	t_global	*data;

	if (s != NULL && s[0])
	{
		add_history(s);
		data = parsing(s, env, *env_v);
		herdoc_execution(data, data->herdoc);
		if (data->error_msg)
		{
			g_global.status_number = 258;
			get_err(data->error_msg, 0);
			destory_data(&data);
			return ;
		}
		if (data->cmd_count == 1 && !data->command_list->name_of_cmd)
		{
			destory_data(&data);
			return ;
		}
		if (data->valid_sntax)
			executor(env_v, data, data->command_list);
		destory_data(&data);
		data = NULL;
	}
}

void	executor(t_env **env, t_global *data, t_cmd *cmd)
{
	t_cmd	*tmp;
	char	**str;
	int		pid;

	str = envir_vars_change(env);
	tmp = cmd;
	pid = -1;
	if (catch_err(cmd, str))
		return ;
	while (cmd)
	{
		if (cmd->blt && cmd->next == NULL && cmd->error_type < 0)
		{
			handle_built_in(cmd, env, str);
			return ;
		}
		if (cmd->next == NULL)
			pid = fork_execute_cmd(data, cmd, env, str);
		else
			fork_execute_cmd(data, cmd, env, str);
		cmd = cmd->next;
	}
	close_pipes_and_wait(data, tmp, pid);
	free_str_arr(str);
}

int	fork_execute_cmd(t_global *data, t_cmd *cmd, t_env **env, char **str)
{
	int	pid;
	int	i;

	i = 0;
	pid = fork();
	sigint1();
	if (pid < 0)
	{
		ft_putstr_fd("pipe Error\n", 2);
		g_global.status_number = 127;
	}
	else if (pid == 0)
	{
		manage_pipe_io(data->p, cmd->read_from_fd, cmd->write_in_fd,
			data->cmd_count);
		if (cmd->blt)
		{
			run_builtin(env, cmd->argv, cmd);
			exit(g_global.status_number);
		}
		check_err(cmd);
		execute_command(cmd->argv, env, str);
	}
	return (pid);
}

void	execute_command(char **args, t_env **env_vars, char **env)
{
	char	*command;

	command = which(env_vars, args[0]);
	if (execve(command, args, env) == -1)
	{
		if (ft_strchr(args[0], '/'))
			print_error(-1, ft_strjoin(args[0], ": no such file or directory"));
		else
			print_error(-1, ft_strjoin(args[0], ": command not found"));
	}
}
