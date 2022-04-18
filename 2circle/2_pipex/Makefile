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

MAN_DIR = ./mandatory_srcs/
MAN_FILES = main.c multi_pipex.c set_cmd.c direct.c free.c
MAN_SRCS = $(addprefix $(MAN_DIR), $(MAN_FILES))
MAN_OBJS = $(MAN_SRCS:.c=.o)
BONUS_DIR = ./bonus_srcs/
BONUS_FILES = main_bonus.c multi_pipex_bonus.c set_cmd_bonus.c direct_bonus.c free_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MAN_OBJS)
endif

all : $(PIPEX)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PIPEX) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $@ ./libft/libft.a $^

bonus :
	make BONUS=1 all

clean : 
	make -C libft clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) ./libft/libft.a
	$(RM) $(PIPEX) 

re : fclean all

.PHONY : all bonus clean fclean re