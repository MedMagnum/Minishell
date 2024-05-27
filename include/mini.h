/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:59:45 by mighmour          #+#    #+#             */
/*   Updated: 2023/03/15 07:48:38 by mighmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "../parsing/libraries.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

char		**ft_split(char const *s, char c);
int			ft_strchr(char *s, int c);
char		*ft_strjoin1(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strstr(char *str, char *to_find);
void		print_error(int error_code, char *message);
void		print_err(char **av);
void		check_err(t_cmd *cmd);
void		ft_echo(char **args, int fd);
void		ft_cd(t_env **env_v, char **av);
void		ft_export(t_env **env_v, char **av, int fd);
void		ft_pwd(t_env **env_v);
void		handle_built_in(t_cmd *cmd, t_env **env, char **str);
void		ft_lstadd_back(t_env **lst, t_env *new);
t_env		*ft_lstnew(char *name, char *data);
int			ft_lstsize(t_env *lst);
t_env		*get_env_value(t_env **env_v, char *name);
void		add_env_var(t_env **env_v, char **spl);
void		check_if_exist(t_env **env_v, char **spl, char **av, int i);
char		*which(t_env **path, char *cmd);
void		free_queue(t_op *head);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		executor(t_env **env, t_global *data, t_cmd *cmd);
int			ft_lstsize(t_env *lst);
void		manage_pipe_io(int **pipes, int read_end, int write_end, int n_cmd);
void		ft_putstr_fd(char *s, int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		free_str_arr(char **arr);
void		execute_command(char **args, t_env **env_vars, char **env);
char		*ft_strtrim(char *s1, char *set);
void		parsing_executing_cmd(t_env **env_v, char *s, char **env);
void		read_get_history(int history, char *s);
void		append_add_value(t_env **env_v, char **spl, int i, char **av);
int			valid_indentifier(char *str);
void		printerror(t_cmd *cmd);
void		print_env_variables(t_env **env_list, char **arguments, int fd);
void		ft_exit(char **args);
void		initialize_env_list(t_env **env_list, char **envp);
void		ft_sort(t_env **env_v);
void		run_builtin(t_env **env_v, char **av, t_cmd *cmd);
void		export_print(t_env **env_v, int fd);
void		ft_unset(t_env **env_v, char **names);
int			fork_execute_cmd(t_global *data, t_cmd *cmd, t_env **env,
				char **str);
void		sigint2(void);
long long	ft_atoi(const char *str);
void		printexit(char **av, int i);
int			catch_err(t_cmd *cmd, char **str);
void		close_pipes_and_wait(t_global *data, t_cmd *tmp, int pid);
char		**envir_vars_change(t_env **env_v);
void		dellocate(char *s1, char *s2);
int			check_absolute_path(char *cmd);
void		herdoc_execution(t_global *data_struct, t_op *del);
char		*get_next_line(int fd);
void		sigint0(void);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		sigint1(void);
void		prepare_export_data(char **spl, char **av, int i, t_env **env_v);
void		destory_data(t_global **global_data);
void		path_err(t_env *path_val);
#endif