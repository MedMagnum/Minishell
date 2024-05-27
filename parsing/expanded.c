/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:51:34 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 04:43:23 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	qot(char *q, char *c, char oppocte)
{
	if (!(*q) && (*c == '\'' || *c == '\"'))
	{
		*q = *c;
		*c = PT;
	}
	else if (*q && *c == *q)
	{
		if (search_chr(c + 1, oppocte, *q) || (*c == '\"' && *(c + 1) == '\"'))
			*c = PT;
		else if (!search_chr(c + 1, *q, 0))
			*c = PT;
		else if ((*c + 1) || spc_token(*(c + 1)) || token(*(c + 1)))
			*c = PT;
		*q = 0;
	}
}

void	quotes_pos(char *input_string)
{
	int		i;
	char	q;
	char	op;

	q = 0;
	i = -1;
	while (input_string[++i])
	{
		qot(&q, input_string + i, op);
		if (q == '\'')
			op = '\"';
		else
			op = '\'';
	}
}

char	*got_expand(char *input_string)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!input_string)
		return (NULL);
	result = 0;
	quotes_pos(input_string);
	while (input_string[i])
	{
		if (input_string[i] == PT)
		{
			result = ft_strjoin_d(result, get_line(input_string, j, i));
			j = i + 1;
		}
		i++;
	}
	if (i > j)
		result = ft_strjoin_d(result, get_line(input_string, j, i));
	free(input_string);
	return (result);
}

char	*final_expand(int *x, char *exp, char *final_expanded)
{
	char	*res_str;

	res_str = final_expanded;
	final_expanded = got_expand(ft_strdup(final_expanded));
	free(res_str);
	if (ft_strlen(final_expanded) == ft_strlen(exp) && *x == DOC)
		*x = EXP_DOC;
	free(exp);
	return (final_expanded);
}
