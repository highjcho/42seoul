# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 15:39:52 by hyunjcho          #+#    #+#              #
#    Updated: 2022/06/20 21:32:39 by hyunjcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

NAME = philo

RM = rm -rf

INCLUDE_DIR = ./includes/

FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

SRCS_DIR = ./srcs/

SRCS = main.c \
		utils.c

MAN_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))

MAN_OBJS = $(MAN_SRCS:.c=.o)

vpath %.c $(SRCS_DIR)

all: $(LIBFT) $(NAME)

%.o: %.c
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)	
	@$(CC) $(FLAG) -c $< -o $@

$(NAME): $(MAN_OBJS)

	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
	@$(CC) $(FLAG) -o $@ $(MAN_OBJS)

clean:
	@$(RM) $(MAN_OBJS)
	@echo "cleaning"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "fcleaning"

re:
	make fclean
	make all

.PHONY: all re clean fclean