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

NAME = Megaphone

CC = c++

FLAG = -Wall -Wextra -Werror -std=c++98

SRCS_DIR = ./srcs/

SRCS = Megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

%.o: %.cpp 
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@$(CC) $(FLAG) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Megaphone" $(WHITE) "..." $(EOC)
	@$(CC) $(FLAG) -o $@ $(OBJS)

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