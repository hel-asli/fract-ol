/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:58:03 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/17 13:59:27 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->img.addr + (y * data->img.line_length + x * (data->img.bpp / 8));
    *(unsigned int *)dst = color;
}