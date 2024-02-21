CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
SRCS = main.c fractol_utils.c data_init.c mandelbrot_render.c fractol_event.c fractol_color.c \
		utils/ft_strlen.c utils/ft_putstr_fd.c utils/ft_strncmp.c utils/ft_check_dbl.c
OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
NAME = fractol
# include $(LIBFT_DIR)/Makefile

all : $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

%.o: %.c fractol.h 
	$(CC) $(CFLAGS) -Imlx -c $< -g -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY : clean
