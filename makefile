CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c fractol_utils.c fractol_init.c fractol_render.c fractol_color.c
OBJS = $(SRCS:.c=.o)
# LIBFT_DIR = libft
# LIBFT_AR = libft.a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
NAME = fractol

all : $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY : clean