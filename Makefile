MAKEFLAGS 			+= --no-print-directory
NAME                = miniRT
LIBFT               = ./libft/
LIBFTA              = $(LIBFT)libft.a
SRC_DIR             = src/
OBJ_DIR             = obj/
INC         		= ./includes/
MLX_DIR             = ./mlx/
MLX				   	= $(MLX_DIR)libmlx_Linux.a
CC                  = cc
CFLAGS              = -Wall -Werror -Wextra 
RM                  = rm -f
MAIN_DIR         = $(SRC_DIR)main.c $(SRC_DIR)parse.c $(SRC_DIR)utils.c

SRCS                = $(MAIN_DIR)
OBJ                 = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
all:                $(NAME)
$(NAME):           	$(LIBFTA) $(OBJ) $(MLX) 
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -I $(MLX_DIR) -L $(MLX_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(LIBFTA):
					@make -C $(LIBFT)
$(OBJ_DIR)%.o:      $(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) -I $(MLX_DIR) -I $(LIBFT) -I $(INC) -c $< -o $@

$(MLX):
					@make -C $(MLX_DIR)
clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C $(LIBFT)
					@make clean -C $(MLX_DIR)
fclean:             clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFTA)
re:                 fclean all
.PHONY:             all clean fclean re