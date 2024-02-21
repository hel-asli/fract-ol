/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:01:18 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/21 20:21:45 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale (double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void julia_render(t_data *data, int x, int y)
{
    t_complex z;
    t_complex c;
    t_color color;
    double tmpx;


    int i = 0;
    c.x = data->x_julia;
    c.y = data->y_julia;
    z.x = (scale(x, data->x0, data->x1, 10, WIDTH) * data->zoom) + data->shift_x;
    z.y = (scale(y , data->y0, data->y1, 0, HEIGHT) * data->zoom) + data->shift_y;
    while ((z.x * z.x + z.y * z.y) <= 4 && i < data->iterations)
    {
        tmpx = ((z.x * z.x) - (z.y * z.y)) + c.x;
        z.y = (2 * z.x * z.y) + c.y;
        z.x = tmpx;
        i++;
    }
    if (i == data->iterations)
        my_mlx_put_pixel(data, x, y, 0x000000);
    else
    {
        my_mlx_put_pixel(data, x, y, calculate_color(&color, i, data->factor));
    }
}

void burningship_set(t_data *data, int x, int y)
{
    t_complex z;
    t_complex c;
    t_color color;
    double tmpx;


    int i = 0;
    z.x = 0;
    z.y = 0;
    c.x = (scale(x, data->x0, data->x1, 10, WIDTH) * data->zoom) + data->shift_x;
    c.y = (scale(y , data->y0, data->y1, 0, HEIGHT) * data->zoom) + data->shift_y;
    while ((z.x * z.x + z.y * z.y) <= 4 && i < data->iterations)
    {
        tmpx = ((z.x * z.x) - (z.y * z.y)) + c.x;
        z.y = fabs((2 * z.x * z.y)) + c.y;
        z.x = tmpx;
        i++;
    }
    if (i == data->iterations)
        my_mlx_put_pixel(data, x, y, 0x000000);
    else
    {
        my_mlx_put_pixel(data, x, y, calculate_color(&color, i, data->factor));
    }
}

void mandelbot_set(t_data *data, int x, int y)
{
    t_complex z;
    t_complex c;
    t_color color;
    double tmpx;


    int i = 0;
    z.x = 0;
    z.y = 0;
    c.x = (scale(x, data->x0, data->x1, 10, WIDTH) * data->zoom) + data->shift_x;
    c.y = (scale(y , data->y0, data->y1, 0, HEIGHT) * data->zoom) + data->shift_y;
    while ((z.x * z.x + z.y * z.y) <= 4 && i < data->iterations)
    {
        tmpx = ((z.x * z.x) - (z.y * z.y)) + c.x;
        z.y = (2 * z.x * z.y) + c.y;
        z.x = tmpx;
        i++;
    }
    if (i == data->iterations)
        my_mlx_put_pixel(data, x, y, 0x000000);
    else
    {
        my_mlx_put_pixel(data, x, y, calculate_color(&color, i, data->factor));
    }
}

void fractol_render(t_data *data)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            if (ft_strncmp(data->title, MANDELBROT, ft_strlen(MANDELBROT)) == 0)
                mandelbot_set(data, x, y);
            else if (ft_strncmp(data->title, JULIA, ft_strlen(JULIA)) == 0)
                julia_render(data, x, y);
            else if (ft_strncmp(data->title, BURNINGSHIP, ft_strlen(BURNINGSHIP)) == 0)
                burningship_set(data, x, y);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}
