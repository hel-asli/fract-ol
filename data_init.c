/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:39:42 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/21 04:08:57 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
	{
		return (len_src);
	}
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

void fractol_data_init(t_data *data, char *str)
{
    if (!data)
    {
        exit(EXIT_FAILURE);
    }
    data->title = malloc(ft_strlen(str) + 1);
    ft_strlcpy(data->title, str, ft_strlen(str) + 1);
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        exit(EXIT_FAILURE);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, data->title);
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
    data->iterations = 50;
    data->factor = 1;
    data->shift_x = 0;
    data->shift_y = 0;
    data->x0 = -2;
    data->x1 = 2;
    data->y0 = -2;
    data->y1 = 2;
    data->zoom = 1;
}