# my directories
LIBFT_DIR = libft
GNL_DIR = get_next_line
FT_PRINTF_DIR = ft_printf
SRC_DIR = src
SRCB_DIR = srcb

# src files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/render.c \
	$(SRC_DIR)/game.c $(SRC_DIR)/utils.c $(SRC_DIR)/hook1.c \
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
	$(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchar.c \
	$(FT_PRINTF_DIR)/ft_putnbr.c $(FT_PRINTF_DIR)/ft_putstr.c \
	$(FT_PRINTF_DIR)/ft_putnbr_hexa.c $(FT_PRINTF_DIR)/ft_putnbr_un.c \
	$(FT_PRINTF_DIR)/ft_putpointer.c $(SRC_DIR)/hook2.c $(SRC_DIR)/helper.c \

SRCB = $(SRCB_DIR)/main_bonus.c $(SRCB_DIR)/map_bonus.c $(SRCB_DIR)/render_bonus.c \
	$(SRCB_DIR)/game_bonus.c $(SRCB_DIR)/utils_bonus.c $(SRCB_DIR)/hook1_bonus.c \
	$(SRCB_DIR)/hook2_bonus.c $(SRCB_DIR)/helper_bonus.c \
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
	$(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchar.c \
	$(FT_PRINTF_DIR)/ft_putnbr.c $(FT_PRINTF_DIR)/ft_putstr.c \
	$(FT_PRINTF_DIR)/ft_putnbr_hexa.c $(FT_PRINTF_DIR)/ft_putnbr_un.c \
	$(FT_PRINTF_DIR)/ft_putpointer.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = src/so_long.h libft/libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h
INCLUDESB = srcb/so_long_bonus.h libft/libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h

LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long
MANDATORY_FLAG = .mandatory_flag
BONUS_FLAG = .bonus_flag

all: $(NAME)

$(NAME): $(MANDATORY_FLAG)

$(MANDATORY_FLAG): $(LIBFT) $(OBJ) $(INCLUDES)
	$(CC) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	touch $(MANDATORY_FLAG)
	rm -rf $(BONUS_FLAG)

bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(LIBFT) $(OBJB) $(INCLUDESB)
	$(CC) $(OBJB) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	touch $(BONUS_FLAG)
	rm -rf $(MANDATORY_FLAG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(BONUS_FLAG)
	rm -f $(MANDATORY_FLAG)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all bonus
