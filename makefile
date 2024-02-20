CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c fractol_utils.c fractol_init.c mandelbrot_render.c fractol_event.c fractol_color.c
OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
NAME = fractol
# include $(LIBFT_DIR)/Makefile

all : $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

%.o: %.c fractol.h 
	$(CC) $(CFLAGS) -Imlx -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY : clean
