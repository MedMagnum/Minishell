/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:16:50 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 07:51:46 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	ft_pwd(t_env **env_list)
{
	char	cwd[1024];
	t_env	*env_var;

	env_var = get_env_value(env_list, "PWD");
	if (env_var && env_var->data_side && chdir(env_var->data_side) == 0
		&& getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		g_global.status_number = 0;
	}
	else
	{
		printf("pwd: error retrieving current directory\n");
		g_global.status_number = 1;
	}
}

char	**envir_vars_change(t_env **env_v)
{
	t_env	*new;
	char	**res;
	char	*buffer;
	int		len;
	int		i;

	new = *env_v;
	i = 0;
	len = ft_lstsize(new);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	while (new)
	{
		buffer = ft_strjoin(new->name_side, "=");
		res[i] = ft_strjoin(buffer, new->data_side);
		free(buffer);
		new = new->next;
		i++;
	}
	res[i] = 0;
	return (res);
}
