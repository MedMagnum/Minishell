# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mighmour <mighmour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 06:59:40 by mighmour          #+#    #+#              #
#    Updated: 2023/03/15 10:39:51 by mighmour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = builtins/cd.c builtins/echo.c builtins/env.c builtins/export.c builtins/unset.c builtins/pwd.c builtins/exit.c builtins/dependencies.c builtins/more_dep.c \
execution/libft_f.c execution/ft_split.c execution/path_related.c execution/linkedlist_utils.c execution/exec_main_task.c execution/utilities.c \
parsing/commands_utils.c parsing/commands.c parsing/commands1.c parsing/errors.c parsing/expand.c parsing/expanded.c parsing/expanded1.c parsing/fill_list.c parsing/fill_structures_tokens.c \
parsing/final_parser.c  parsing/utils.c  parsing/in_or_file.c parsing/is_builted.c parsing/libft_utils.c parsing/libft.c parsing/linked_list_op.c \
parsing/minishell_utils.c parsing/parsing.c parsing/tokens.c parsing/tokens1.c parsing/variables.c \
gnl/get_next_line.c gnl/get_next_line_utils.c \
run_heredoc.c  handle_signals.c\
execution/dep.c execution/main.c

CC = gcc

CFLAGS = -c -I /Users/mighmour/.brew/opt/readline/include

OBJCT = ${SRC:.c=.o}

$(NAME): $(OBJCT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME) : $(OBJCT)
	@$(CC)  $(CFALGS) -lreadline -I /Users/mighmour/.brew/opt/readline/include -L /Users/mighmour/.brew/opt/readline/lib  $(OBJCT) -o $(NAME)
clean :
	@rm -f $(OBJCT)
fclean : clean
	@rm -f $(NAME)
re : fclean all

.PHONY: clean all fclean re
