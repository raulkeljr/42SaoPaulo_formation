NAME =		cub3D
SRCS_DIR =	srcs
OBJS_DIR =	.objs
LIBFT_DIR =	libft
LIBFT =		$(LIBFT_DIR)/libft.a
MLX_DIR =	minilibx
MLX =		$(MLX_DIR)/libmlx.a

SRCS =		$(SRCS_DIR)/main.c \
			$(SRCS_DIR)/gnl.c \
			$(SRCS_DIR)/rayx.c \
			$(SRCS_DIR)/rays.c \
			$(SRCS_DIR)/input_check_args.c \
			$(SRCS_DIR)/input_read_n_validate.c \
			$(SRCS_DIR)/input_parse_identif.c \
			$(SRCS_DIR)/input_parse_map.c \
			$(SRCS_DIR)/utils.c \
			$(SRCS_DIR)/utils2.c \
			$(SRCS_DIR)/ft_game.c \
			$(SRCS_DIR)/key_update.c \
			$(SRCS_DIR)/raycast.c \
			$(SRCS_DIR)/raycast_intercept.c \
			$(SRCS_DIR)/render_2d.c \
			$(SRCS_DIR)/render_3d.c \
			$(SRCS_DIR)/sprite.c \
			$(SRCS_DIR)/utils3.c \
			$(SRCS_DIR)/ft_clear.c \
			$(SRCS_DIR)/ft_error.c \
			$(SRCS_DIR)/save_bmp_file.c

OBJS =		$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

CC =		clang
HEAD =		-I./include -I./$(LIBFT_DIR) -I./$(MLX_DIR)
CFLAGS =	-Wall -Werror -Wextra -g -fsanitize=address
LFLAGS =	-lbsd -lm -lX11 -lXext \
			-L ./$(LIBFT_DIR) -lft \
			-L ./$(MLX_DIR) -lmlx
RM =		/bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(OBJS) $(HEAD) $(CFLAGS) $(LFLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

$(MLX):
		make -C $(MLX_DIR)

clean:
		make clean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)
		$(RM) $(OBJS_DIR)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)
		$(RM) *.bmp

re: fclean all

.PONY: all clean fclean re
