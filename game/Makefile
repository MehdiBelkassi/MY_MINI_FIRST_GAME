# Directories
LIBFT_DIR = libft
GNL_DIR = get_next_line
SRC_DIR = src
FT_PRINTF_DIR = ft_printf

# Source files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/render.c \
      $(SRC_DIR)/game.c $(SRC_DIR)/utils.c $(SRC_DIR)/hook.c \
      $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
      $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchar.c \
      $(FT_PRINTF_DIR)/ft_putnbr.c $(FT_PRINTF_DIR)/ft_putstr.c \
      $(FT_PRINTF_DIR)/ft_putnbr_hexa.c $(FT_PRINTF_DIR)/ft_putnbr_un.c \
      $(FT_PRINTF_DIR)/ft_putpointer.c


OBJ = $(SRC:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

# Include paths - adding get_next_line directory
INCLUDES = -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(FT_PRINTF_DIR)

# Libft library
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long

# Main target
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

# Object files compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Libft compilation
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all