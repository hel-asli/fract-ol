/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:39:42 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/17 15:45:04 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractol_data_init(t_data *data, char *title)
{
    if (!data)
    {
        exit(EXIT_FAILURE);
    }
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        exit(EXIT_FAILURE);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, title);
    if (!data->win_ptr)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(EXIT_FAILURE);
    }
    data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    if (!data->img.img)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(EXIT_FAILURE);
    }
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_length, &data->img.endian);
    if(!data->img.addr)
    {
        mlx_destroy_image(data->mlx_ptr, data->img.img);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(EXIT_FAILURE);
    }
    data->iterations = 1000;
}