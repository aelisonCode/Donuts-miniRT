# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 11:11:45 by aelison           #+#    #+#              #
#    Updated: 2025/01/15 17:28:30 by mravelon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

NAME_DB = no_leaks

LIB_PATH = ./libft/

LIB = $(LIB_PATH)libft.a

PRINT = $(LIB_PATH)ft_printf/libftprintf.a

SRC = src/ft_program.c \
	  errors/ft_error.c \
	  errors/check_file.c \
	  errors/check_obj.c \
	  errors/check_view_obj.c \
	  errors/utils.c \
	  errors/param_error.c\
	  errors/param_view_err.c\
	  mlx/ft_init_mlx.c \
	  mlx/close_mlx.c \
	  mlx/event.c \
	  mlx/utils.c \
	  utils/ft_control_string.c \
	  utils/for_error.c\
	  utils/ft_atof.c\
	  utils/ft_free.c \
	  libft/get_next_line/get_next_line.c \
	  libft/get_next_line/get_next_line_utils.c \

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

ARG = "maps/moi.rt"

GRIND = --leak-check=full --show-leak-kinds=all --track-fds=yes

DEBUG = $(CFLAGS) -g

MINILBX_CLONE = git@github.com:42Paris/minilibx-linux.git

MINILBX_PATH = ./minilibx-linux/

MINILBX = ${MINILBX_PATH}/libmlx_Linux.a

LINKING = -L$(MINILBX_PATH) -lmlx -lXext -lX11 -lm

all: $(OBJ_DIR) $(MINILBX) $(NAME)

run: all
	./$(NAME) $(ARG)

grind: $(MINILBX) $(NAME_DB)

v: fclean grind
	valgrind $(GRIND) ./$(NAME_DB) $(ARG)
n:
	@norminette $(SRC) header/

$(NAME): $(OBJ) $(LIB) $(PRINT)
	@echo "Creating miniRT exec..."
	@$(CC)  $(CFLAGS) ${OBJ} ${LIB} ${PRINT} $(MINILBX) $(LINKING) -o $(NAME)
	@echo "Creating Successful !"

$(NAME_DB): $(OBJ) $(LIB) $(PRINT)
	@echo "Creating no_leaks exec..."
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIB) $(PRINT) $(MINILBX) $(LINKING) -o $(NAME_DB)
	@echo "Creating Successful !"

$(LIB):
	@echo "Compiling Libft..."
	@make -C $(LIB_PATH) -s bonus

$(PRINT): $(LIB)
	@echo "Compiling ft_printf..."
	@make -C $(LIB_PATH)ft_printf/ -s all

$(MINILBX):
	@if [ ! -d "$(MINILBX_PATH)" ]; then \
		git clone $(MINILBX_CLONE); \
	fi
	@echo "Compiling minilibx..."
	@make -C $(MINILBX_PATH) -s all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@${CC} $(CFLAGS)  -o $@ -c $<

clean:
	@echo "Clean obj files..."
	@make -C $(LIB_PATH) -s clean
	@make -C $(LIB_PATH)ft_printf/ -s clean
	@rm   -rf $(OBJ_DIR)
	@echo "Complete clean !"

fclean: clean
	@make -C $(LIB_PATH) -s fclean
	@make -C $(LIB_PATH)ft_printf/ -s fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_DB)
	clear

re: fclean all

.PHONY: re fclean clean all
