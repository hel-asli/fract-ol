# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:24:47 by hel-asli          #+#    #+#              #
#    Updated: 2024/03/25 00:28:00 by hel-asli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
SRCS = main.c  data_init.c fractol_render.c fractol_event.c fractol_color.c \
	   utils/ft_strlen.c utils/ft_putstr_fd.c utils/ft_strcmp.c utils/ft_check_dbl.c fractol_event_helper.c
OBJS = $(SRCS:.c=.o)
OBJ_FLAGS = -Imlx
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f
NAME = fractol

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

%.o: %.c fractol.h 
	$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -g -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY : clean