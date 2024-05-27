/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:09:47 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 06:47:49 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	quote_found(char c, int *s, int *d)
{
	if (c == '\'' && !(*d))
		*s = !(*s);
	if (c == '\"' && !(*s))
		*d = !(*d);
}

char	*status(char *input_result, int *i, int *j)
{
	char	*expanded_result;
	char	*status_num;

	status_num = ft_itoa(g_global.status_number);
	expanded_result = ft_strjoin_d(input_result, status_num);
	*i += 1;
	*j = (*i) + 1;
	return (expanded_result);
}

char	*status_return(char *string_input, char *old_res, int *index)
{
	char	*expanded_result;

	expanded_result = old_res;
	if (index[0] != index[1])
		expanded_result = new_str(string_input, expanded_result, index[1],
				index[0]);
	expanded_result = status(expanded_result, &index[1], &index[0]);
	return (expanded_result);
}

char	*final_result(t_vars *variable, char *input_string)
{
	char	*string;
	int		index[2];
	int		quotes[2];

	begin_data(index, &string, quotes);
	while (input_string[index[1]])
	{
		quote_found(input_string[index[1]], &quotes[0], &quotes[1]);
		if (input_string[index[1]] == '$' && \
			ft_isdigit(input_string[index[1] + 1]) && !quotes[0])
			string = got_number(input_string, string, &index[1], &index[0]);
		else if (utils_checker(input_string, index[1], quotes[0]))
			string = variable_valid(input_string, string, index, &variable);
		else if (utils2_checker(input_string, index[1], quotes[0]))
			string = status_return(input_string, string, index);
		index[1]++;
	}
	if (index[1] != index[0])
		string = new_str(input_string, string, index[1],
				index[0]);
	return (string);
}
