# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 11:11:45 by aelison           #+#    #+#              #
#    Updated: 2025/03/07 08:17:33 by aelison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

NAME_DB = no_leaks


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
	  color/obj.c \
	  color/color_effect.c \
	  errors/ft_error.c \
	  errors/mandatory_obj.c \
	  errors/name_file.c \
	  errors/verify.c \
	  errors/verify_obj.c \
	  errors/void_file.c \
	  errors/mandatory_prime.c \
	  mlx/mouse_to_obj.c \
	  mlx/menu.c \
	  mlx/menu_output.c \
	  mlx/ft_init_mlx.c \
	  mlx/close_mlx.c \
	  mlx/event.c \
	  mlx/event_control.c \
	  mlx/utils.c \
	  mlx/launch.c \
	  mlx/obj.c \
	  utils/ft_control_string.c \
	  utils/ft_atof.c\
	  utils/ft_free.c \
	  utils/ft_struct.c \
	  utils/get_type.c \
	  utils/check_error.c \
	  utils/ft_strcmp.c \
	  utils/value_error.c \
	  parsing/required_obj.c \
	  parsing/components.c \
	  parsing/physics_obj.c \
	  projection/ray.c \
	  projection/ray_tracing.c \
	  projection/init_projection.c \
	  projection/shadow_effect.c \
	  projection/shadow_obj.c \
	  projection/normal_vect.c \
	  projection/utils.c \
	 
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARG = "maps/moi.rt"

GRIND = --leak-check=full --show-leak-kinds=all --track-fds=yes

DEBUG = $(CFLAGS) -g

LIB_PATH = ./libft

LIB = $(LIB_PATH)/libft.a

MINILBX_URL = https://github.com/42paris/minilibx-linux

MINILIBX_TAR = minilibx-linux.tgz

MINILBX_PATH = ./minilibx-linux

MINILBX = ${MINILBX_PATH}/libmlx_Linux.a

LINKING = -L$(MINILBX_PATH) -lmlx -lXext -lX11 -lm -O3

all: $(OBJ_DIR) $(NAME)

minilibx: $(MINILBX_PATH)

run: all
	./$(NAME) $(ARG)

grind: $(MINILBX) $(NAME_DB)

v: fclean grind
	valgrind $(GRIND) ./$(NAME_DB) $(ARG)
n:
	@norminette $(SRC) $(LIB_PATH) header/

$(NAME): $(OBJ) $(LIB) $(MINILBX)
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

$(MINILBX_PATH):
	@echo "Downloading sources...."
	@wget $(MINILBX_URL)
	#@tar -xzvf $(MINILIBX_TAR)
	#@rm -rf $(MINILIBX_TAR)
	@echo "Donwloading done !"

$(MINILBX):
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
	@make -C$(MINILBX_PATH) -s clean
	@echo "Cleaning minilibx"
	@echo "Executable [$(NAME)] removed!"

re: fclean all

.PHONY: re fclean clean all run grind v n
