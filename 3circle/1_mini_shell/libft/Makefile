# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:57:26 by hyunjcho          #+#    #+#              #
#    Updated: 2022/06/08 18:37:58 by jonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = ft_bzero.c ft_calloc.c ft_isdigit.c ft_isalpha.c ft_isalnum.c \
		ft_strlen.c ft_itoa.c ft_strdup.c ft_strjoin.c ft_substr.c ft_split.c ft_strlcpy.c \
		ft_strcmp.c ft_strncmp.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c 
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

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
