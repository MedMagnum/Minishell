/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:07:09 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:35:42 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

int	ft_lstsize(t_env *lst)
{
	unsigned int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
	new->next = NULL;
}

t_env	*ft_lstnew(char *name, char *data)
{
	t_env	*res;

	res = malloc(sizeof(t_env));
	if (!res)
		return (NULL);
	res->name_side = name;
	res->data_side = data;
	res->next = NULL;
	return (res);
}

t_env	*get_env_value(t_env **env_v, char *name)
{
	while (*env_v)
	{
		if (ft_strcmp((*env_v)->name_side, name) == 0)
			return (*env_v);
		env_v = &(*env_v)->next;
	}
	return (NULL);
}

void	add_env_var(t_env **env_v, char **spl)
{
	t_env	*new;

	new = *env_v;
	new = ft_lstnew(ft_strdup(spl[0]), ft_strdup(spl[1]));
	ft_lstadd_back(env_v, new);
}
