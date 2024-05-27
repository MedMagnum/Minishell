/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:05:14 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 07:32:20 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libraries.h"
# include "structs.h"
# include <stdio.h>

void		free_d(t_vars *head);
char		*the_expand(int *x, char *exp, t_global *general, char *line);
size_t		count_len_dop(t_op *head);
char		**array_to_treate(t_cmd *cmd);
int			lines_t_fill(char *line, int x, t_global *general, t_cmd *cmd_list);
int			herdocument_parsing(t_cmd *cmd_list, t_global *general, char *str);
int			commandline(char *str, int i, t_cmd *cmd_list, t_global *general);
void		exprs(t_global *general, char *line, t_cmd *command_list);
void		command_line(t_global *general);
t_cmd		*go_next(t_cmd *head);
void		add_cmd(t_cmd **cmd, t_cmd *to_add);
char		*get_line(char *cmd, int a, int b);
int			utils_checker(char *input_string, int i, int x);
int			id_command(t_cmd *head);
int			search_chr(char *string_input, char chr, char end);
t_cmd		*cmd_add(t_cmd *head);
void		return_error(t_global *gnl, char *str);
void		pipes_errors(t_global *info, char *input, int index);

void		errors_check(t_global *gnl, char *input);
int			utils2_checker(char *input_string, int i, int x);
void		quote_found(char c, int *s, int *d);
char		*status(char *input_result, int *i, int *j);
char		*status_return(char *string_input, char *old_res, int *index);
char		*final_result(t_vars *variable, char *input_string);
void		qot(char *q, char *c, char oppocte);
void		quotes_pos(char *input_string);
char		*got_expand(char *input_string);
char		*final_expand(int *x, char *exp, char *final_expanded);
char		*got_number(char *s, char *old_res, int *i, int *j);
void		begin_data(int *index, char **Resulted_String, int *quotes);
char		*new_str(char *str_input, char *old_res, int i, int j);
char		*to_list_vars(int *i, int *j, char *old_res, t_vars **dollars);
char		*variable_valid(char *s, char *old_res, int *index,
				t_vars **dollars);
int			set_command(char *input, int *array, t_global *data, t_cmd **head);
int			find_the_close(char c, char *input);
t_cmd		*fill_list(char *input, t_global *global_struct);
void		infile(t_cmd *command, char *name);
void		outfile(t_cmd *command_line, char *name);
char		*var_value(char *dollar_variable, t_env *env);
void		args(t_cmd *cmd, char *argument);
void		put_struct(char *str, int x, t_global *general, t_cmd *cmd_list);
void		final_parse(t_global *final_data_resulted);
void		what_to_do_d_p(t_global *final_data_resulted, t_cmd *cmd,
				int pipe_index);
int			in_or_out_file(t_global *general_data, t_cmd *command_list,
				char *string_input, int *i);
void		sigint0(void);
t_vars		*fill_var(char *variable_string, char *value_string);
int			spc_token(char c);
void		int_handler(int sig);
int			chr_token(char *input_string);
int			builted(char *str);
void		builted_or_not(t_cmd *command_line);
int			valid_variable(char *input_string);
char		*ft_itoa(int number);
int			outfile_token(char c);
char		*var_get(char *input_string);
void		len(long nbre, int *x);
char		*ft_strjoin_d(char *string1, char *string2);
t_vars		*vars_expansion(char *input_string, t_env *env);
int			ft_isalpha(char chr);
int			append_token(char *str, int i);
int			ft_isdigit(char chr);
t_op		*create_op(char *str);
int			herdoc_token(char *str, int i);
int			alpha_valid_var(char ch);
int			ft_strlen(const char *string);
char		*ft_strjoin(char *string1, char *string2);
char		*ft_strdup(char *string);
int			ft_strcmp(char *string1, char *string2);
t_op		*get_last(t_op *head_ptr);
int			token(char c);
t_vars		*go_next_d(t_vars *head_ptr);
int			infile_token(char c);
char		*line_double(char *string_input);
void		pb(t_op **head, t_op *new);
void		pbd(t_vars **head, t_vars *to_push);
void		free_strs(char *first_string, char *second_string);
char		*line_single(char *string_input);
char		*gt_line(char *input_string);
t_global	*parsing(char *input, char **ev, t_env *env_list);
int			ft_isalnum(char c);
void		herdc(t_global *data, t_cmd *cmd_list, int x, char *del);

#endif