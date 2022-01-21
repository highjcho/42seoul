# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 10:58:45 by hyunjcho          #+#    #+#              #
#    Updated: 2022/01/05 10:58:55 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

OBJS = ft_printf.o ft_printf_utils.o ft_calloc.o ft_itoa.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
