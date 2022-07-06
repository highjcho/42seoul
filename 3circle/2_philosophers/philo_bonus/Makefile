# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 15:39:52 by hyunjcho          #+#    #+#              #
#    Updated: 2022/07/05 17:06:53 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

NAME = philo

RM = rm -rf

INCLUDE_DIR = ./includes/

FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

SRCS_DIR = ./srcs/

SRCS = main.c \
		init.c \
		make_mutex.c \
		make_thread.c \
		philo.c \
		task.c \
		utils.c \

MAN_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))

MAN_OBJS = $(MAN_SRCS:.c=.o)

vpath %.c $(SRCS_DIR)

all: $(NAME)

%.o: %.c
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)	
	@$(CC) $(FLAG) -c $< -o $@

$(NAME): $(MAN_OBJS)

	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
	@$(CC) $(FLAG) -o $@ $(MAN_OBJS)

clean:
	@$(RM) $(MAN_OBJS)
	@echo $(CYAN) "Cleaning..."
	
fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) "Fcleaning..."

re:
	@make fclean
	make all

.PHONY: all re clean fclean