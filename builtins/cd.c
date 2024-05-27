/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:22:15 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:04:42 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	set_env_var(t_env **env_v, char *name, char *value)
{
	t_env	*env_var;
	t_env	*new_var;

	env_var = get_env_value(env_v, name);
	if (env_var)
	{
		free(env_var->data_side);
		env_var->data_side = ft_strdup(value);
	}
	else
	{
		new_var = ft_lstnew(ft_strdup(name), ft_strdup(value));
		ft_lstadd_back(env_v, new_var);
	}
}

void	update_pwd(t_env **env_v)
{
	char	*cwd;

	set_env_var(env_v, "OLDPWD", get_env_value(env_v, "PWD")->data_side);
	cwd = getcwd(NULL, 0);
	set_env_var(env_v, "PWD", cwd);
	free(cwd);
	g_global.status_number = 0;
}

void	ft_cd(t_env **env_v, char **av)
{
	char	*path;
	t_env	*home;

	path = NULL;
	if (!av[1] || (av[1][0] == '~' && av[1][1] == '\0'))
	{
		home = get_env_value(env_v, "HOME");
		if (home)
			path = ft_strdup(home->data_side);
		else
			path = NULL;
	}
	else if (av[1])
		path = ft_strdup(av[1]);
	if (path)
	{
		if (chdir(path) == 0)
			update_pwd(env_v);
		else
		{
			g_global.status_number = 1;
			printf("cd: %s: %s\n", path, strerror(errno));
		}
		free(path);
	}
}
