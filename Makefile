NAME = so_long
MLX = mlx

CFLAGS = -Wall -Wextra -Werror

CC	 = gcc

HEADER = solong.h

RM = rm -f

SRC =	main.c draw_functions.c

OBJS	= ${SRC:.c=.o}

all:	$(NAME)

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

#.c.o:
#	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

$(NAME): $(OBJS) ${HEADER}
	make -C $(MLX)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a $(OBJS) -o $(NAME)

#$(NAME):	$(OBJS) ${HEADER}
#				$(CC) $(OBJS) $(CFLAGS) -g -o $(NAME)

#bonus:	${SERVER_BON} ${CLIENT_BON}

clean:
	make -C $(MLX) clean
	${RM} ${OBJS}

fclean:	 clean
		${RM} ${NAME}

re: 	fclean all

.PHONY:  all clean fclean re