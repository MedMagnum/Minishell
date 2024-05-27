/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:03:42 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:09:05 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

char	*ft_strjoin_d(char *string1, char *string2)
{
	char	*resulted_string;

	resulted_string = ft_strjoin(string1, string2);
	free_strs(string1, string2);
	return (resulted_string);
}

char	*got_number(char *s, char *old_res, int *i, int *j)
{
	int		a;
	int		b;
	char	*part;
	char	*res;

	a = *j;
	b = *i;
	part = get_line(s, a, b);
	res = ft_strjoin_d(old_res, part);
	*i += 1;
	*j = b + 1;
	return (res);
}

int	utils2_checker(char *input_string, int i, int x)
{
	if (input_string[i] == '$' && input_string[i + 1] == '?' && !x)
		return (1);
	else
		return (0);
}

int	utils_checker(char *input_string, int i, int x)
{
	if (input_string[i] == '$' && (ft_isalpha(input_string[i + 1])
			|| input_string[i + 1] == '_') && !x)
		return (1);
	else
		return (0);
}
