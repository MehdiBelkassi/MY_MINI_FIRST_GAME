# Directories
LIBFT_DIR = libft
GNL_DIR = get_next_line
SRC_DIR = src
SRCB_DIR = srcb
FT_PRINTF_DIR = ft_printf

# Source files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/render.c \
      $(SRC_DIR)/game.c $(SRC_DIR)/utils.c $(SRC_DIR)/hook1.c \
      $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
      $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchar.c \
      $(FT_PRINTF_DIR)/ft_putnbr.c $(FT_PRINTF_DIR)/ft_putstr.c \
      $(FT_PRINTF_DIR)/ft_putnbr_hexa.c $(FT_PRINTF_DIR)/ft_putnbr_un.c \
      $(FT_PRINTF_DIR)/ft_putpointer.c $(SRC_DIR)/hook2.c $(SRC_DIR)/helper.c

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

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

# Include paths
INCLUDES = -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(FT_PRINTF_DIR)

# Libft library
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long
BONUS_FLAG = .bonus_flag

# Main target
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

# Bonus target - using a flag file to prevent relinking
bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(LIBFT) $(OBJB) 
	$(CC) $(OBJB) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	touch $(BONUS_FLAG)

# Object files compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Libft compilation
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(BONUS_FLAG)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all bonus
# # Directories
# LIBFT_DIR = libft
# GNL_DIR = get_next_line
# SRC_DIR = src
# SRCB_DIR = srcb
# FT_PRINTF_DIR = ft_printf

# # Source files
# SRC = $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/render.c \
#       $(SRC_DIR)/game.c $(SRC_DIR)/utils.c $(SRC_DIR)/hook1.c \
#       $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
#       $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchar.c \
#       $(FT_PRINTF_DIR)/ft_putnbr.c $(FT_PRINTF_DIR)/ft_putstr.c \
#       $(FT_PRINTF_DIR)/ft_putnbr_hexa.c $(FT_PRINTF_DIR)/ft_putnbr_un.c \
#       $(FT_PRINTF_DIR)/ft_putpointer.c $(SRC_DIR)/hook2.c $(SRC_DIR)/helper.c

# SRCB = $(SRCB_DIR)/main_bonus.c $(SRCB_DIR)/map_bonus.c $(SRCB_DIR)/render_bonus.c \
#       $(SRCB_DIR)/game_bonus.c $(SRCB_DIR)/utils_bonus.c $(SRCB_DIR)/hook1_bonus.c \
#       $(SRCB_DIR)/hook2_bonus.c $(SRCB_DIR)/helper_bonus.c \
#       $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
#       $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchar.c \
#       $(FT_PRINTF_DIR)/ft_putnbr.c $(FT_PRINTF_DIR)/ft_putstr.c \
#       $(FT_PRINTF_DIR)/ft_putnbr_hexa.c $(FT_PRINTF_DIR)/ft_putnbr_un.c \
#       $(FT_PRINTF_DIR)/ft_putpointer.c

# OBJ = $(SRC:.c=.o)
# OBJB = $(SRCB:.c=.o)

# # Compiler settings
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

# # Include paths
# INCLUDES = -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(FT_PRINTF_DIR)

# # Libft library
# LIBFT = $(LIBFT_DIR)/libft.a

# NAME = so_long

# # Main target
# all: $(NAME)

# $(NAME): $(LIBFT) $(OBJ)
# 	$(CC) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

# # Bonus target
# bonus: fclean $(LIBFT) $(OBJB)
# 	$(CC) $(OBJB) $(LIBFT) $(MLXFLAGS) -o $(NAME)

# # Object files compilation
# %.o: %.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# # Libft compilation
# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# clean:
# 	rm -f $(OBJ) $(OBJB)
# 	$(MAKE) -C $(LIBFT_DIR) clean

# fclean: clean
# 	rm -f $(NAME)
# 	$(MAKE) -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: clean fclean re all bonus