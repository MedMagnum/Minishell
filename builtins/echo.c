/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:20:24 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 09:44:24 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

int	the_n_check(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'n' && str[0] == '-')
			i++;
		else
			break ;
	}
	if (!str[i])
		return (1);
	return (0);
}

void	ft_echo(char **args, int fd)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (args[1] != NULL && the_n_check(args[1]))
	{
		newline = 0;
		i++;
	}
	if (args[1][0] == '0' && args[1][1] == '\0')
		ft_putstr_fd("0\n", fd);
	while (args[i] != NULL)
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1] != NULL)
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", fd);
	g_global.status_number = 0;
}
