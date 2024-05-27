/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:03:09 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:03:11 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_static
{
	int				status_number;
	int				get_nb;
	int				fd_new;
}					t_static;

t_static			g_global;

typedef struct exp
{
	char			*variable;
	char			*value;
	struct exp		*next;
}					t_vars;
typedef struct s_op
{
	char			*str;
	int				valid;
	int				cmd_id;
	struct s_op		*next;
}					t_op;

typedef struct s_env
{
	char			*name_side;
	char			*data_side;
	struct s_env	*next;
}					t_env;
typedef struct s_cmd
{
	t_op			*args;
	char			**argv;
	int				cmd_id;
	char			*infile;
	char			*outfile;
	char			*error_msg_s;
	int				create;
	t_vars			*variables;
	char			*name_of_cmd;
	char			*cmd_string;
	int				blt;
	int				status_nbr;
	char			*erno_fil;
	int				error_type;
	int				write_in_fd;
	int				read_from_fd;
	struct s_cmd	*prev;
	struct s_cmd	*next;
	int				hdc;
	int				hdc_file;
	int				hdc_p[2];
	int				out_mode;

}					t_cmd;

typedef struct s_global
{
	char			*error_msg;
	t_op			*herdoc;
	t_env			*env_list;
	int				valid_sntax;
	t_cmd			*command_list;
	char			**env;
	int				cmd_count;
	int				**p;

}					t_global;

#endif