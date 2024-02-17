/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:09:33 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/17 16:09:28 by hel-asli         ###   ########.fr       */
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
}   t_data;

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

void ft_putstr_fd(char *str, int fd);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *str);
void fractol_data_init(t_data *data, char *title);
void fractol_render(t_data *data);
void my_mlx_put_pixel(t_data *data, int x, int y, int color);
void mandelbot_set(t_data *data, int x, int y);


# endif
