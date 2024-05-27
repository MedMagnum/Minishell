/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:12:32 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 09:45:18 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini.h"

void	int_sig(int signal)
{
	if (g_global.get_nb == 0)
	{
		g_global.status_number = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (g_global.get_nb == 1)
	{
		g_global.status_number = 1;
		g_global.get_nb = -1;
		write(1, "\n", 1);
		close(0);
	}
}

void	quite_sig(int sig)
{
	(void)sig;
	write(1, "Quit\n", 5);
	g_global.status_number = 131;
}

void	sigint1(void)
{
	signal(SIGINT, int_sig);
	signal(SIGQUIT, quite_sig);
}

void	sigint2(void)
{
	signal(SIGINT, int_sig);
	signal(SIGQUIT, SIG_IGN);
}
