/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:20:57 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 06:20:01 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

int	is_valid_numeric_input(const char *str)
{
	int					sign;
	unsigned long long	num;
	int					i;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if (num > (unsigned long long)LLONG_MAX)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **args)
{
	if (args[1])
	{
		if (!is_valid_numeric_input(args[1]))
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		else if (args[2])
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			exit(1);
		}
		else
		{
			exit(ft_atoi(args[1]));
		}
	}
	exit(g_global.status_number);
}
