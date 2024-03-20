/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:58:03 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/15 00:12:38 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
			+ x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	scale(double num
		, double new_min, double new_max, double old_max)
{
	double	new_range;

	new_range = new_max - new_min;
	return (new_range * num / old_max + new_min);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	calculate_color(t_color *color, int iteration, int factor)
{
	color->r = (iteration * factor) % 255;
	color->g = (iteration * (factor + 10)) % 255;
	color->b = (iteration * (factor + 15)) % 255;
	return (create_trgb(0, color->r, color->g, color->b));
}
