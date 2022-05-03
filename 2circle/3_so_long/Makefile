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

MAN_DIR = ./srcs/
MAN_FILES = so_long.c check_map.c get_next_line.c ft_split.c print_map.c play_game.c utils.c
MAN_SRCS = $(addprefix $(MAN_DIR), $(MAN_FILES))
MAN_OBJS = $(MAN_SRCS:.c=.o)
BONUS_DIR = ./bonus_srcs/
BONUS_FILES = so_long_bonus.c check_map_bonus.c get_next_line_bonus.c ft_split_bonus.c print_map_bonus.c play_game_bonus.c effect_bonus.c utils_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MAN_OBJS)
endif

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
	$(RM) $(MAN_OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) ./libft/libft.a
	$(RM) $(SO_LONG) 

re : fclean all

.PHONY : all bonus clean fclean re
