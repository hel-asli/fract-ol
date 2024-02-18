/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:01:18 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/17 22:32:56y hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale (double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void mandelbot_set(t_data *data, int x, int y)
{
    t_complex z;
    t_complex c;
    double tmpx;


    int i = 0;
    z.x = 0;
    z.y = 0;
    c.x = scale(x, -2, 2, 0 , WIDTH);
    c.y = scale(y , -2, 2, 0, HEIGHT);
    int color;
    while ((z.x * z.x + z.y * z.y) <= 4 && i < data->iterations)
    {
        tmpx = ((z.x * z.x) - (z.y * z.y)) + c.x;
        z.y = (2 * z.x * z.y) + c.y;
        z.x = tmpx;
        i++;
    }
    if (i == data->iterations)
        color = 0xFFFFFF;
    else
    {
        color = data->color * i;
    }
    my_mlx_put_pixel(data, x, y, color);
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
            mandelbot_set(data, x, y);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}