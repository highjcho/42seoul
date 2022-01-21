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

OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	   ft_toupper.o ft_tolower.o ft_strlen.o  ft_strncmp.o ft_strlcpy.o ft_strlcat.o ft_atoi.o ft_itoa.o \
	   ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strdup.o ft_substr.o \
	   ft_strjoin.o ft_strtrim.o ft_split.o ft_strmapi.o ft_striteri.o \
	   ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_calloc.o \
	   ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o 

B_OBJS = ft_lstnew.o ft_lstlast.o ft_lstmap.o \
		ft_lstadd_front.o ft_lstadd_back.o \
		ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstsize.o

ifdef W_BONUS
	OBJECTS = $(OBJS) $(B_OBJS)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	${AR} $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus :
	make W_BONUS=1 all

clean : 
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
