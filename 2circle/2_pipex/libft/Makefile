# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:57:26 by hyunjcho          #+#    #+#              #
#    Updated: 2021/12/06 15:35:58 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = get_next_line.c ft_strlen.c ft_strncmp.c ft_strdup.c ft_strjoin.c ft_split.c ft_bzero.c ft_calloc.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	${AR} $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	
clean : 
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
