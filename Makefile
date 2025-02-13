# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 11:11:45 by aelison           #+#    #+#              #
#    Updated: 2025/02/13 10:26:25 by aelison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

NAME_DB = no_leaks

LIB_PATH = ./libft/

LIB = $(LIB_PATH)libft.a

SRC = src/ft_program.c \
	  obj_control/obj_moves.c \
	  obj_control/sphere/sphere.c \
	  obj_control/cylinder/cylinder.c \
	  obj_control/cylinder/utils.c \
	  obj_control/cylinder/edge.c \
	  obj_control/plane/plane.c \
	  obj_control/utils.c \
	  obj_control/transform.c \
	  vect/operations.c \
	  vect/control.c \
	  color/color.c \
	  color/create.c \
	  color/obj.c \
	  errors/ft_error.c \
	  errors/check_file.c \
	  errors/check_obj.c \
	  errors/check_view_obj.c \
	  errors/utils.c \
	  errors/param_error.c\
	  errors/param_view_err.c\
	  mlx/mouse_to_obj.c \
	  mlx/menu.c \
	  mlx/menu_output.c \
	  mlx/ft_init_mlx.c \
	  mlx/close_mlx.c \
	  mlx/event.c \
	  mlx/utils.c \
	  mlx/launch.c \
	  mlx/obj.c \
	  utils/ft_control_string.c \
	  utils/ft_atof.c\
	  utils/ft_free.c \
	  utils/ft_struct.c \
	  utils/get_type.c \
	  parsing/required_obj.c \
	  parsing/components.c \
	  parsing/physics_obj.c \
	  projection/ray.c \
	  projection/ray_tracing.c \
	  projection/init_projection.c \
	  projection/shadow_effect.c \
	  projection/shadow_obj.c \

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

ARG = "maps/moi.rt"

GRIND = --leak-check=full --show-leak-kinds=all --track-fds=yes

DEBUG = $(CFLAGS) -g

MINILBX_CLONE = git@github.com:42Paris/minilibx-linux.git

MINILBX_PATH = ./minilibx-linux/

MINILBX = ${MINILBX_PATH}/libmlx_Linux.a

LINKING = -L$(MINILBX_PATH) -lmlx -lXext -lX11 -lm -O3

all: $(OBJ_DIR) $(MINILBX) $(NAME)

run: all
	./$(NAME) $(ARG)

grind: $(MINILBX) $(NAME_DB)

v: fclean grind
	valgrind $(GRIND) ./$(NAME_DB) $(ARG)
n:
	@norminette $(SRC) header/

$(NAME): $(OBJ) $(LIB)
	@echo "Creating miniRT exec [$(NAME)]"
	@$(CC)  $(CFLAGS) ${OBJ} ${LIB} $(MINILBX) $(LINKING) -o $(NAME)
	@echo "Creating [$(NAME)] Successful !"

$(NAME_DB): $(OBJ) $(LIB)
	@echo "Creating no_leaks exec [$(NAME_DB)]"
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIB) $(MINILBX) $(LINKING) -o $(NAME_DB)
	@echo "Creating [$(NAME_DB)] Successful !"

$(LIB):
	@echo "Creating Libft archive [$@]"
	@make -C $(LIB_PATH) -s bonus
	@echo "Archive [$@] create !"

$(MINILBX):
	@if [ ! -d "$(MINILBX_PATH)" ]; then \
		git clone $(MINILBX_CLONE); \
	fi
	@echo "Creating Minilibx archive [$@]"
	@make -C $(MINILBX_PATH) -s all
	@echo "Archive [$@] create !"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling [$<]"
	@${CC} $(CFLAGS) -c $< -o $@

clean:
	@echo "Clean obj files"
	@make -C $(LIB_PATH) -s clean
	@rm   -rf $(OBJ_DIR)
	@echo "Complete clean !"

fclean: clean
	@make -C $(LIB_PATH) -s fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_DB)
	@echo "Executable [$(NAME)] removed!"

re: fclean all

.PHONY: re fclean clean all
