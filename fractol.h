/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:09:33 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/20 05:07:50 by hel-asli         ###   ########.fr       */
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
#define WIDTH 1000
#define HEIGHT 1000


// colors

#define ERROR_MASSAGE "ENTER A VALIDE FRACTOL NAME\n./fractolt mandelbrot\n./fractol julia real imag\n"

#define BLACK       0x000000
#define WHITE       0xFFFFFF


#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

#define A 0
#define S 1 
#define D 2
#define W 13
#define C 8
#define R 15
#define B 11

#define SCROLL_UP 4
#define SCROLL_DOWN 5

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
	int factor;
	double shift_x;
	double shift_y;
	double x0;
	double x1;
	double y0;
	double y1;
	double zoom;
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
}	t_color;

void ft_putstr_fd(char *str, int fd);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *str);
void fractol_data_init(t_data *data, char *title);
void fractol_render(t_data *data);
void my_mlx_put_pixel(t_data *data, int x, int y, int color);
void mandelbot_set(t_data *data, int x, int y);
int	create_trgb(int t, int r, int g, int b);
int calculate_color(t_color *color, int iteration, int factor);
void ft_shift_helper(t_data *data, int keysym);
void ft_color_change(t_data *data, int keysym);
void ft_change_instraction(t_data *data, int keysym);
int key_handler(int keysym, void *param);
double scale (double unscaled_num, double new_min, double new_max, double old_min, double old_max);

# endif
