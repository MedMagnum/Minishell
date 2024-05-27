/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:53:18 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 09:39:25 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	handle_built_in(t_cmd *cmd, t_env **env, char **str)
{
	int	stdin_copy;
	int	error_code;

	stdin_copy = dup(0);
	error_code = cmd->error_type;
	if (error_code > 0)
	{
		g_global.status_number = 1;
		ft_putstr_fd(strerror(error_code), 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	run_builtin(env, cmd->argv, cmd);
	if (str)
		free_str_arr(str);
	dup2(stdin_copy, 0);
	close(stdin_copy);
}

void	manage_pipe_io(int **pipes, int read_end, int write_end, int n_cmd)
{
	int	i;

	i = 0;
	while (i < n_cmd - 1)
	{
		if (pipes[i][0] != read_end)
			close(pipes[i][0]);
		if (pipes[i][1] != write_end)
			close(pipes[i][1]);
		i++;
	}
	dup2(read_end, 0);
	dup2(write_end, 1);
}

void	print_input_to_fd(char *line, int fd)
{
	char	*res;

	res = NULL;
	res = ft_strjoin(line, "\n");
	ft_putstr_fd(res, fd);
	free(res);
}

void	exit_shell(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	char	*input_string;
	t_env	*env_list;
	int		history_fd;

	(void)av;
	(void)ac;
	env_list = NULL;
	initialize_env_list(&env_list, env);
	history_fd = open("/tmp/.mini_History", O_RDWR | O_APPEND, 0644);
	input_string = NULL;
	read_get_history(history_fd, input_string);
	while (1337)
	{
		sigint0();
		input_string = readline(PROMPT);
		if (!input_string)
			exit_shell();
		if (input_string)
			print_input_to_fd(input_string, history_fd);
		parsing_executing_cmd(&env_list, input_string, env);
		free(input_string);
	}
	close(history_fd);
}
