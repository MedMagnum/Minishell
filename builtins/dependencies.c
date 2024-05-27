/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependencies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:24:25 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:51:45 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	check_err(t_cmd *cmd)
{
	if (cmd->erno_fil)
	{
		ft_putstr_fd(ft_strdup(cmd->erno_fil), 2);
		ft_putstr_fd(ft_strdup(": "), 2);
	}
	if (cmd->error_type == 0)
		print_error(1, "ambiguous error");
	if (cmd->error_type > 0)
		print_error(1, strerror(cmd->error_type));
}

void	print_err(char **av)
{
	char	*res;

	res = NULL;
	res = ft_strjoin(av[1], " : not a valid identifier\n");
	ft_putstr_fd(res, 2);
	free(res);
	g_global.status_number = 1;
}

char	*ft_strtrim(char *s1, char *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

void	append_add_value(t_env **env_v, char **spl, int i, char **av)
{
	t_env	*new;
	int		len;
	char	*res;

	new = *env_v;
	len = ft_strlen(spl[0]);
	free(spl[0]);
	spl[0] = ft_substr(av[i], 0, len - 1);
	new = get_env_value(env_v, spl[0]);
	if (new)
	{
		res = new->data_side;
		new->data_side = ft_strjoin(new->data_side, spl[1]);
		if (res)
			free(res);
	}
	else
		add_env_var(env_v, spl);
}

void	path_err(t_env *path_val)
{
	if (!path_val)
		print_error(-1, "no such file or directory");
}
