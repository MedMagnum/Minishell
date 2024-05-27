/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:26:46 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:37:16 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	prepare_export_data(char **spl, char **av, int i, t_env **env_v)
{
	int	len;

	len = ft_strlen(av[i]);
	spl[1] = NULL;
	spl[0] = ft_substr(av[i], 0, (len - ft_strlen(spl[1])));
	if (!valid_indentifier(spl[0]))
	{
		print_err(av);
		free(spl[0]);
		return ;
	}
	check_if_exist(env_v, spl, av, 0);
	free(spl[0]);
}

void	run_builtin(t_env **env_v, char **av, t_cmd *cmd)
{
	if ((ft_strcmp(av[0], "echo")) == 0)
		ft_echo(av, cmd->write_in_fd);
	else if ((ft_strcmp(av[0], "pwd")) == 0)
		ft_pwd(env_v);
	else if ((ft_strcmp(av[0], "cd")) == 0)
		ft_cd(env_v, av);
	else if ((ft_strcmp(av[0], "env")) == 0)
		print_env_variables(env_v, av, cmd->write_in_fd);
	else if ((ft_strcmp(av[0], "export")) == 0)
		ft_export(env_v, av, cmd->write_in_fd);
	else if ((ft_strcmp(av[0], "unset")) == 0)
		ft_unset(env_v, av);
	else if ((ft_strcmp(av[0], "exit")) == 0)
		ft_exit(av);
}
