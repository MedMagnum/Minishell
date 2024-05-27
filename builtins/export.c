/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:19:10 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:21:05 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	ft_sort(t_env **env_v)
{
	t_env	*tmp;
	int		size;
	char	*name_swap;
	char	*data_swap;

	size = ft_lstsize(*env_v);
	while (size--)
	{
		tmp = (*env_v);
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name_side, tmp->next->name_side) > 0)
			{
				name_swap = tmp->name_side;
				tmp->name_side = tmp->next->name_side;
				tmp->next->name_side = name_swap;
				data_swap = tmp->data_side;
				tmp->data_side = tmp->next->data_side;
				tmp->next->data_side = data_swap;
			}
			tmp = tmp->next;
		}
	}
}

void	export_print(t_env **env_list, int fd)
{
	t_env	*current;

	ft_sort(env_list);
	current = *env_list;
	while (current)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(current->name_side, fd);
		if (current->data_side != NULL)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(current->data_side, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		current = current->next;
	}
}

void	check_if_exist(t_env **env_v, char **spl, char **av, int i)
{
	t_env	*new;

	new = *env_v;
	if (av[i][ft_strlen(spl[0]) - 1] != '+')
	{
		new = get_env_value(env_v, spl[0]);
		if (new != NULL)
		{
			free(new->data_side);
			new->data_side = ft_strdup(spl[1]);
		}
		else
			add_env_var(env_v, spl);
	}
	else if (av[i][ft_strlen(spl[0]) - 1] == '+')
		append_add_value(env_v, spl, i, av);
}

void	help_export(t_env **env_vars, char *arg, char **args, int index)
{
	char	*key_value[2];
	int		arg_len;

	arg_len = ft_strlen(args[index]);
	if (arg)
	{
		key_value[1] = ft_strdup(arg + 1);
		key_value[0] = ft_substr(args[index], 0, ((arg_len - 1)
					- ft_strlen(key_value[1])));
		if (!valid_indentifier(key_value[0]))
		{
			print_err(args);
			free(key_value[0]);
			free(key_value[1]);
			return ;
		}
		else if (key_value[1] != NULL && key_value[0] != NULL)
			check_if_exist(env_vars, key_value, args, index);
		free(key_value[1]);
		free(key_value[0]);
	}
	else if (arg == NULL && get_env_value(env_vars, args[index]) == NULL)
		prepare_export_data(key_value, args, index, env_vars);
}

void	ft_export(t_env **env, char **args, int fd)
{
	int		i;
	char	*equals;
	char	*error_msg;

	i = 1;
	if (!args[i])
		export_print(env, fd);
	while (args[i])
	{
		g_global.status_number = 0;
		equals = ft_strstr(args[i], "=");
		if ((!args[i][ft_strlen(equals)] || (!ft_isalpha(args[i][0])
			&& args[i][0] != '_')))
		{
			error_msg = ft_strjoin(args[i], " : not a valid identifier\n");
			ft_putstr_fd(error_msg, 2);
			free(error_msg);
			g_global.status_number = 1;
		}
		else
			help_export(env, equals, args, i);
		i++;
	}
}
