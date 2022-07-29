# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 12:10:20 by hyunjcho          #+#    #+#              #
#    Updated: 2022/06/14 12:10:21 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INCLUDE_DIR = ./includes/

RM = rm -rf

LIBFT = ./libft/libft.a

FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

COMPILE_FLAG = -I/goinfre/hyunjcho/homebrew/opt/readline/include

LINK_FLAG = -lreadline -L/goinfre/hyunjcho/homebrew/opt/readline/lib


SRCS_DIR = ./srcs/

SRCS = main.c \
		init/init_env.c \
		init/init.c \
		signal/signal.c \
		parse/tokenize.c \
		parse/tokenlist.c \
		parse/make_token.c \
		parse/ast.c \
		parse/astnode.c \
		parse/env_substitution.c \
		parse/quote.c \
		parse/syntaxcheck.c \
		parse/ast_merge.c \
		parse/pipelinelist.c \
		redirect/redirect_process.c \
		redirect/here_doc.c \
		redirect/dup_file.c \
		builtins/mini_echo.c \
		builtins/mini_cd.c \
		builtins/mini_pwd.c \
		builtins/mini_export.c \
		builtins/mini_unset.c \
		builtins/mini_env.c \
		builtins/mini_exit.c \
		execute/execute.c \
		execute/builtin.c \
		execute/execve.c \
		execute/fork.c \
		utils/setattr.c \
		utils/env_utils.c \
		utils/utils.c \
		utils/free.c \
		utils/all_free.c \
		utils/art.c \
		utils/get_next_line.c


MAN_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))
MAN_OBJS = $(MAN_SRCS:.c=.o)

vpath %.c $(SRCS_DIR)

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(FLAG) $(COMPILE_FLAG) -c $< -o $@

$(NAME): $(MAN_OBJS)
	@$(CC) $(FLAG) $(COMPILE_FLAG) $(LINK_FLAG) $(LIBFT) -o $@ $(MAN_OBJS)
	@echo "making minishell"

$(LIBFT):
	@make -C ./libft

clean:
	@$(RM) $(MAN_OBJS)
	@make clean -C ./libft
	@echo "cleaning"
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft
	@echo "fcleaning"

re:
	make fclean
	make all

.PHONY: all re clean fclean
