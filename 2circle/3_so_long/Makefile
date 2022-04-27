# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 19:06:40 by hyunjcho          #+#    #+#              #
#    Updated: 2022/04/27 19:11:09 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MFALG = -lmlx -framework OpenGL -framework AppKit -lz
AR = ar -rcs
RM = rm -f

MAN_DIR = ./
MAN_FILES = so_long.c check_map.c get_next_line.c ft_split.c print_map.c utils.c
MAN_SRCS = $(addprefix $(MAN_DIR), $(MAN_FILES))
OBJS = $(MAN_SRCS:.c=.o)
# BONUS_DIR = ./bonus_srcs/
# BONUS_FILES = main_bonus.c pipex_bonus.c set_cmd_bonus.c free_bonus.c
# BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ifdef BONUS
# 	OBJS = $(BONUS_OBJS)
# else
# 	OBJS = $(MAN_OBJS)
# endif

all : $(SO_LONG)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SO_LONG) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(MFALG) -o $@ ./libft/libft.a $^
 
bonus :
	make BONUS=1 all

clean : 
	make -C libft clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) ./libft/libft.a
	$(RM) $(SO_LONG) 

re : fclean all

.PHONY : all bonus clean fclean re
