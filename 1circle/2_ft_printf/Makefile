# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 17:01:48 by hyunjcho          #+#    #+#              #
#    Updated: 2022/01/19 17:01:52 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC_DIR = ./srcs/
SRC_FILES = ft_printf.c ft_flag.c ft_print_int.c ft_print_char.c ft_print_str.c ft_print_u_int.c ft_print_hex.c ft_print_addr.c ft_util.c 
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS_DIR = ./bonus_srcs/
BONUS_SRC_FILES = ft_printf_bonus.c ft_flag_bonus.c ft_print_int_bonus.c ft_print_char_bonus.c ft_print_str_bonus.c ft_print_u_int_bonus.c ft_print_hex_bonus.c ft_print_addr_bonus.c ft_util_bonus.c 
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRC_FILES))
OBJ_DIR = ./
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -cr $@ $^

bonus :
	make "OBJS = $(BONUS_OBJS)" all

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
