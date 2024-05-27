/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:17:35 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:19:02 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	initialize_env_list(t_env **env_list, char **envp)
{
	int		i;
	char	**key_value;

	i = 0;
	while (envp[i])
	{
		key_value = ft_split(envp[i], '=');
		if (key_value[0] != NULL && key_value[1] != NULL)
			ft_lstadd_back(env_list, ft_lstnew(key_value[0], key_value[1]));
		free(key_value);
		i++;
	}
}

void	handle_env_error(t_env **env_list, char **args)
{
	char	*error_msg;

	g_global.status_number = 127;
	if (get_env_value(env_list, "PATH"))
	{
		error_msg = ft_strjoin(args[1], " : No such file or directory\n");
		ft_putstr_fd(error_msg, 2);
		free(error_msg);
	}
	else
	{
		error_msg = ft_strjoin("env", " : No such file or directory\n");
		ft_putstr_fd(error_msg, 2);
		free(error_msg);
	}
}

void	print_env_variables(t_env **env_list, char **arguments, int fd)
{
	t_env	*current_variable;

	current_variable = *env_list;
	if (!arguments[1] && get_env_value(env_list, "PATH"))
	{
		while (current_variable)
		{
			if (current_variable->data_side != NULL)
			{
				ft_putstr_fd(current_variable->name_side, fd);
				ft_putstr_fd("=", fd);
				ft_putstr_fd(current_variable->data_side, fd);
				ft_putstr_fd("\n", fd);
			}
			current_variable = current_variable->next;
		}
	}
	else
		handle_env_error(env_list, arguments);
}
