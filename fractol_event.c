/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:02:16 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/16 00:29:35 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_boundries_calc(t_data *data, double offest_x,
		double offest_y, double zoom_factor)
{
	data->x0 = offest_x + zoom_factor * (data->x0 - offest_x);
	data->x1 = offest_x + zoom_factor * (data->x1 - offest_x);
	data->y0 = offest_y + zoom_factor * (data->y0 - offest_y);
	data->y1 = offest_y + zoom_factor * (data->y1 - offest_y);
}

int	mouse_julia(int x, int y, void *param)
{
	t_data	*data;
	double	offset_x;
	double	offset_y;

	data = (t_data *)param;
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (1);
	offset_x = scale(x, data->x0, data->x1, WIDTH);
	offset_y = scale(y, data->y0, data->y1, HEIGHT);
	if (data->julia_move == 1)
	{
		data->x_julia = offset_x;
		data->y_julia = offset_y;
	}
	fractol_render(data);
	return (1);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	t_data	*data;
	double	zoom_factor;
	double	offset_x;
	double	offset_y;

	data = (t_data *)param;
	if (x < 0 || y < 0)
		return (1);
	zoom_factor = 1;
	offset_x = scale(x, data->x0, data->x1, WIDTH);
	offset_y = scale(y, data->y0, data->y1, HEIGHT);
	if (button == SCROLL_UP)
		zoom_factor = 1.2;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.8;
	if (button == 1 && !ft_strncmp(data->title, JULIA, ft_strlen(JULIA) + 1))
		data->julia_move = 0;
	else if (button == 2
		&& !ft_strncmp(data->title, JULIA, ft_strlen(JULIA) + 1))
		data->julia_move = 1;
	fractol_boundries_calc(data, offset_x, offset_y, zoom_factor);
	fractol_render(data);
	return (0);
}
