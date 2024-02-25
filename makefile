# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-asli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:24:47 by hel-asli          #+#    #+#              #
#    Updated: 2024/02/25 18:24:51 by hel-asli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
SRCS = main.c fractol_utils.c data_init.c fractol_render.c fractol_event.c fractol_color.c \
	   utils/ft_strlen.c utils/ft_putstr_fd.c utils/ft_strncmp.c utils/ft_check_dbl.c fractol_event_helper.c
OBJS = $(SRCS:.c=.o)
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx_linux
else
	INCLUDES = -Imlx
endif
RM = rm -f
NAME = fractol

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

%.o: %.c fractol.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -g -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY : clean
