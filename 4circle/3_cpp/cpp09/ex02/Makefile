# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 19:15:57 by hyunjcho          #+#    #+#              #
#    Updated: 2023/04/03 20:09:21 by hyunjcho         ###   ########.fr        #
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

NAME = PmergeMe

CXX = c++

FLAG = -Wall -Wextra -Werror -std=c++98

SRCS_DIR = ./

FILES = main.cpp \
		PmergeMe.cpp

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

%.o: %.cpp 
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@$(CXX) $(FLAG) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@echo $(WHITE) "Building for" $(YELLOW) "$(NAME)" $(WHITE) "..." $(EOC)
	@$(CXX) $(FLAG) -o $@ $(OBJS)

clean:
	@$(RM) $(OBJS)
	@echo $(CYAN) "Cleaning..."
	
fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) "Fcleaning..."

re:
	@make fclean
	make all

.PHONY: all re clean fclean