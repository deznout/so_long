NAME = so_long
MLX = mlx

CFLAGS = -Wall -Wextra -Werror

CC	 = gcc

HEADER = solong.h

RM = rm -f

SRC =	main.c draw_functions.c ft_split.c checkUtils.c keyhook.c movements.c ft_itoa.c

OBJS	= ${SRC:.c=.o}

all:	$(NAME)

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(NAME): $(OBJS) ${HEADER}
	make -C $(MLX)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
	make -C $(MLX) clean
	${RM} ${OBJS}

fclean:	 clean
		${RM} ${NAME}

re: 	fclean all

.PHONY:  all clean fclean re