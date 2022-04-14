# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 19:06:40 by hyunjcho          #+#    #+#              #
#    Updated: 2022/03/29 19:06:46 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPEX = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

MAIN_FILE = main.c
PIPEX_DIR = ./srcs/
PIPEX_MAIN = $(addprefix $(PIPEX_DIR), $(MAIN_FILE))
PIPEX_FILES = pipex.c set_arg.c utils.c
PIPEX_SRCS = $(addprefix $(PIPEX_DIR), $(PIPEX_FILES))
PIPEX_OBJS = $(PIPEX_SRCS:.c=.o)

all : $(PIPEX)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PIPEX) : $(PIPEX_MAIN) $(PIPEX_OBJS)
	make -C libft
	$(CC) $(CFLAGS) ./libft/libft.a -o $@ $^

clean : 
	make -C libft clean
	$(RM) $(PIPEX_OBJS)

fclean : clean
	$(RM) ./libft/libft.a
	$(RM) $(PIPEX)

re : fclean all

.PHONY : all bonus clean fclean re