/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:19:40 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:24:32 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	help_unset(t_env **env_list, char **unset_names, int i)
{
	t_env	*current_node;
	t_env	*prev_node;

	prev_node = *env_list;
	current_node = prev_node->next;
	while (current_node)
	{
		if (!ft_strcmp(current_node->name_side, unset_names[i]))
		{
			prev_node->next = current_node->next;
			if (current_node->name_side)
				free(current_node->name_side);
			if (current_node->data_side)
				free(current_node->data_side);
			free(current_node);
			break ;
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
	g_global.status_number = 0;
}

void	unset_error_msg(char **unset_args, int i)
{
	char	*error_msg;

	error_msg = NULL;
	g_global.status_number = 1;
	ft_putstr_fd("unset", 2);
	error_msg = ft_strjoin(unset_args[i], ": not a valid identifier\n");
	ft_putstr_fd(error_msg, 2);
	free(error_msg);
}

void	ft_unset(t_env **env_v, char **names)
{
	int		i;
	t_env	*current_env_var;
	int		len;

	current_env_var = NULL;
	i = 1;
	len = ft_strlen(names[i]);
	while (names[i])
	{
		if (!valid_indentifier(names[i]))
			unset_error_msg(names, i);
		else if (!ft_strcmp((*env_v)->name_side, names[i])
			&& get_env_value(env_v, names[i]))
		{
			current_env_var = *env_v;
			*env_v = (*env_v)->next;
			if (current_env_var)
				free(current_env_var);
		}
		else if (get_env_value(env_v, names[i]))
			help_unset(env_v, names, i);
		i++;
	}
}
