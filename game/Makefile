SRC = src/main.c src/map.c src/render.c src/game.c src/utils.c src/hook.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean 
