/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libraries.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 04:53:43 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:28:29 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARIES_H
# define LIBRARIES_H

# include "libraries.h"
# include "minishell.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DOC 56
# define N_AMB 22
# define IF 23
# define OF 20
# define N 0
# define EXP_DOC 36
# define PT -1
# define CMD 9
# define ARG 101
# define PROMPT "\033[1;35mMyBash\033[0m\U0001f600\033[1;92m$ \033[0m"
# define PT_D "\033[92mherdoc>\033[0m"
# define ERROR_PROMPT "\033[91;1mMyBash\U0001F622[91;1m:->\033[0m\n"
# define ERR "\U0001f622 "
# define COLOR_PRM "\033[94mMyBash\033[0m"
# define RED_IN "\033[91m"
# define RED_OUT "\033[0m"

#endif