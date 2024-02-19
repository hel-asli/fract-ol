CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c fractol_utils.c fractol_init.c mandelbrot_render.c fractol_event.c fractol_color.c
OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = fractol

all : $(NAME) 

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $<

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

$(LIBFT) : $(LIBFT_DIR)/libft.h
	@echo "make libft"
	@make -C $(LIBFT_DIR)
clean :
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re : fclean all
.PHONY : clean
