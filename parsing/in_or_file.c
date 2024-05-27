/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_or_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:00:08 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 09:21:01 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	int_handler(int sig)
{
	(void)sig;
	g_global.status_number = 1;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint0(void)
{
	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	in_or_out_file(t_global *general_data, t_cmd *command_list,
		char *string_input, int *i)
{
	int	specifier;
	int	j;

	j = *i;
	specifier = 0;
	if (string_input[j] == '<')
	{
		errors_check(general_data, string_input + j + 1);
		if (!general_data->error_msg)
			*i += lines_t_fill(string_input + j + 1, IF, general_data,
					command_list) + 1;
		specifier = 1;
	}
	else if (string_input[j] == '>')
	{
		errors_check(general_data, string_input + j + 1);
		if (!general_data->error_msg)
			*i += lines_t_fill(string_input + j + 1, OF, general_data,
					command_list) + 1;
		specifier = 1;
	}
	return (specifier);
}
