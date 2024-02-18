/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:09:33 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/18 02:09:15 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

// includes
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
// fractols

#define MANDELBROT "mandelbrot"
#define JULIA "julia"
#define WIDTH 800
#define HEIGHT 800


// colors

#define BLACK       0x00000050
#define WHITE       0xFFFFFF50
#define RED         0xFF000050
#define GREEN       0x00FF0050
#define BLUE        0x0000FF50
#define YELLOW      0xFFFF0050
#define CYAN        0x00FFFF50
#define MAGENTA     0xFF00FF50
#define GRAY        0x80808050

typedef struct s_img
{
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
} t_img;

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    t_img img;
	int	iterations;
	int color;
}   t_data;

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

typedef struct s_color
{
	int r;
	int g;
	int b;
	int a;
}	t_color;

void ft_putstr_fd(char *str, int fd);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *str);
void fractol_data_init(t_data *data, char *title);
void fractol_render(t_data *data);
void my_mlx_put_pixel(t_data *data, int x, int y, int color);
void mandelbot_set(t_data *data, int x, int y);


# endif
