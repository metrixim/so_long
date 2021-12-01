NAME = so_long

SRCS = src/so_long.c src/init.c src/parse_map.c utils/get_next_line.c utils/utils.c src/print_map.c src/init_sprites.c src/move.c utils/itoa.c

FLAGS = -Wall -Wextra -Werror -g

HEADER = so_long.h

MINILIB_X = libmlx.a

MINILIB_X_FLAGS = -framework OpenGL -framework AppKit 

MINILIB_X_PATH = ./minilibx/libmlx.a 

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER) Makefile
	gcc ${FLAGS} -c $< -o $@

$(NAME): ${OBJS} 
		make -C ./minilibx
		gcc ${FLAGS} ${MINILIB_X_FLAGS} ${MINILIB_X_PATH} ${OBJS} -o ${NAME}

all: ${NAME}

bonus: re

clean: 
	make -C ./minilibx clean
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} 
	rm -f ${MINILIB_X}

re: fclean all

.PHONY: all clean fclean re

	