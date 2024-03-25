/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:39:42 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/25 00:11:23 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_intialize_data(t_data *data)
{
	data->iterations = 50;
	data->factor = 1;
	data->shift_x = 0;
	data->shift_y = 0;
	data->x0 = -2;
	data->x1 = 2;
	data->y0 = -2;
	data->y1 = 2;
	data->zoom = 1;
	data->julia_move = 1;
}

// void	error_handler(t_data *data)
// {
// 	(void)data;
// 	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	// mlx_destroy_image(data->mlx_ptr, data->img.img);
// 	// free(data->mlx_ptr);
// 	// free(data->title);
// 	exit(EXIT_FAILURE);
// }

void	fractol_data_init(t_data *data, char *str)
{
	data->title = str;
	if (!data->title)
		return ;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, data->title);
	if (!data->win_ptr)
		exit(EXIT_FAILURE);
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.img)
		exit(EXIT_FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		exit(EXIT_FAILURE);
	ft_intialize_data(data);
}
