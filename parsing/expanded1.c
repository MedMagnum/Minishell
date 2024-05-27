/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:21:28 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 06:42:27 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	begin_data(int	*index, char	**Resulted_String, int	*quotes)
{
	index[0] = 0;
	quotes[0] = 0;
	*Resulted_String = 0;
	index[1] = 0;
	quotes[1] = 0;
}

char	*new_str(char *str_input, char *old_res, int i, int j)
{
	char	*partie;
	char	*result;

	partie = get_line(str_input, j, i);
	result = ft_strjoin_d(old_res, partie);
	return (result);
}

char	*to_list_vars(int *i, int *j, char *old_res, t_vars **dollars)
{
	char	*res;

	res = ft_strjoin(old_res, (*dollars)->value);
	*i += ft_strlen((*dollars)->variable);
	*j = (*i) + 1;
	*dollars = (*dollars)->next;
	if (old_res)
		free(old_res);
	return (res);
}

char	*variable_valid(char *s, char *old_res, int *index, \
		t_vars	**dollars)
{
	char	*result_string;

	result_string = old_res;
	if (index[0] != index[1])
		result_string = new_str(s, result_string, index[1], index[0]);
	result_string = to_list_vars(&index[1], &index[0], result_string, dollars);
	return (result_string);
}
