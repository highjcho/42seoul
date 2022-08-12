# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 15:39:52 by hyunjcho          #+#    #+#              #
#    Updated: 2022/08/05 17:24:58 by heehkim          ###   ########.fr        #
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

NAME = cub3D

RM = rm -rf

INCLUDE_DIR = ./includes/

FLAG = -Wall -Wextra -Werror -g3 -I $(INCLUDE_DIR)

LIBFT = ./libft/libft.a

SRCS_DIR = ./srcs/

SRCS = main.c \
		init/init.c \
		map/check_info.c \
		map/check_map.c \
		map/make_map.c \
		play/prepare_draw.c \
		play/draw.c \
		play/prepare_play.c \
		play/play.c \
		utils/get_next_line.c \
		utils/utils.c

MAN_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))

MAN_OBJS = $(MAN_SRCS:.c=.o)

MODE = EVAL
ifeq ($(MODE), EVAL)
	MLX_DIR = ./mlx
else ifeq ($(MODE), M1)
	MLX_DIR = ./mlx_m1
endif

MLX = $(MLX_DIR)/libmlx.dylib

MLXFLAG = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

vpath %.c $(SRCS_DIR)

all: $(NAME)

%.o: %.c
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@$(CC) $(FLAG) -c $< -o $@

$(NAME): $(MAN_OBJS) $(LIBFT) $(MLX)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
	@$(CC) $(FLAG) $(LIBFT) $(MLXFLAG) -o $@ $(MAN_OBJS)
	@install_name_tool -change libmlx.dylib $(MLX) $(NAME)

$(MLX):
	@make -s -C $(MLX_DIR)

$(LIBFT):
	@make -s -C ./libft

clean:
	@$(RM) $(MAN_OBJS)
	make clean -C $(MLX_DIR)
	@make clean -s -C ./libft
	@echo $(CYAN) "Cleaning..."
	
fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C ./libft
	@echo $(RED) "Fcleaning..."

re:
	@make fclean
	make all

.PHONY: all re clean fclean
