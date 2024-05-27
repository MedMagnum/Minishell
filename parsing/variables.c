/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:40:47 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:09:30 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	alpha_valid_var(char ch)
{
	if (!spc_token(ch) && (ft_isalnum(ch) || ch == '_'))
		return (1);
	else
		return (0);
}

char	*var_get(char *input_string)
{
	int		i;
	char	*result;

	i = 0;
	while (input_string[i] && alpha_valid_var(input_string[i]))
		i++;
	result = get_line(input_string, 0, i);
	return (result);
}

t_vars	*vars_expansion(char *input_string, t_env *env)
{
	int		index;
	t_vars	*dollar_variable;
	char	*var;
	t_vars	*head;

	index = 0;
	head = NULL;
	while (input_string[index])
	{
		if (input_string[index] == '$' && valid_variable(input_string + index
				+ 1))
		{
			var = var_get(input_string + index + 1);
			index += ft_strlen(var);
			dollar_variable = fill_var(var, var_value(var, env));
			pbd(&head, dollar_variable);
		}
		else
			index++;
	}
	return (head);
}

char	*var_value(char *dollar_variable, t_env *env)
{
	int	i;
	int	len;

	len = ft_strlen(dollar_variable);
	i = 0;
	while (env)
	{
		if (!ft_strcmp(dollar_variable, env->name_side))
			return (ft_strdup(env->data_side));
		env = env->next;
	}
	return (ft_strdup("'\0"));
}

t_vars	*fill_var(char *variable_string, char *value_string)
{
	t_vars	*var_result;

	var_result = malloc(sizeof(t_vars));
	if (var_result == 0)
		return (NULL);
	var_result->variable = variable_string;
	var_result->value = value_string;
	return (var_result);
}
