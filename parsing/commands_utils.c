/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:00:50 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 02:35:39 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	free_d(t_vars *head)
{
	t_vars	*ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr->value);
		free(ptr->variable);
		free(ptr);
	}
}

char	*the_expand(int *x, char *exp, t_global *general, char *line)
{
	t_vars	*vars;
	char	*result;

	if (*x == DOC)
		result = ft_strdup(exp);
	else
	{
		vars = vars_expansion(line, general->env_list);
		result = final_result(vars, exp);
		free_d(vars);
	}
	if (result && !result[0])
	{
		if (*x == IF || *x == OF)
			*x = N_AMB;
		else
			*x = N;
	}
	return (result);
}

size_t	count_len_dop(t_op *head)
{
	if (!head)
		return (0);
	return (count_len_dop(head->next) + 1);
}

char	**array_to_treate(t_cmd *cmd)
{
	int		size;
	int		i;
	char	**resulted_array;
	t_op	*head;

	size = count_len_dop(cmd->args) + 1;
	resulted_array = malloc((size + 1) * sizeof(char *));
	if (!resulted_array)
		return (NULL);
	resulted_array[0] = ft_strdup(cmd->name_of_cmd);
	resulted_array[size] = NULL;
	head = cmd->args;
	i = 0;
	while (head && ++i < size)
	{
		resulted_array[i] = ft_strdup(head->str);
		head = head->next;
	}
	return (resulted_array);
}
