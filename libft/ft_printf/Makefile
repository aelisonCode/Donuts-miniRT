NAME = libftprintf.a

SOURCES = ft_hexa_x.c \
	ft_printf_decimal.c \
	ft_printf_ptr.c \
	ft_printf_u.c \
	ft_printf_x.c \
	ft_printf_bigx.c \
	ft_printf.c \
	ft_print_to_format.c \
	ft_printf_char.c \
	ft_printf_string.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr_unsigned.c \
	ft_putstr.c \
	ft_hexa_ptr.c

OBJECTS = ${SOURCES:.c=.o}

VPATH =  ../../libft/

LIB_PATH = ${VPATH}/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJECTS} ${LIB_PATH}
	cp ${LIB_PATH} ${NAME}
	ar -rc ${NAME} ${OBJECTS}

${LIB_PATH}:
	make -C ${VPATH} all

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	@make -C ${VPATH} clean
	@rm -f ${OBJECTS}

fclean: clean
	@make -C ${VPATH} fclean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
