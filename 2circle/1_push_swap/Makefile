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

PUSH_SWAP = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MAIN_FILE = main.c
PS_DIR = ./srcs/push_swap/
PS_MAIN = $(addprefix $(PS_DIR), $(MAIN_FILE))
PS_FILES = make_stack.c fill_stack.c push_swap.c command1.c command2.c less_5.c \
small_part.c small_part_3a.c small_part_3b.c small_part_4.c sort.c utils.c
PS_SRCS = $(addprefix $(PS_DIR), $(PS_FILES))
PS_OBJS = $(PS_SRCS:.c=.o)
CHECKER_DIR = ./srcs/checker/
CHECKER_MAIN = $(addprefix $(CHECKER_DIR), $(MAIN_FILE))
CHECKER_FILES = get_cmd.c do_push_swap.c command1_checker.c command2_checker.c
CHECKER_SRCS = $(addprefix $(CHECKER_DIR), $(CHECKER_FILES))
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(PUSH_SWAP) $(CHECKER)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP): $(PS_MAIN) $(PS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(CHECKER): $(PS_OBJS) $(CHECKER_MAIN) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	$(RM) $(PS_OBJS) $(CHECKER_OBJS)

fclean : clean
	$(RM) $(PUSH_SWAP) $(CHECKER)

re : fclean all

.PHONY : all bonus clean fclean re
