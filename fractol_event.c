/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:02:16 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/22 03:54:09 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_shift_helper(t_data *data, int keysym)
{
	if (keysym == A || keysym == LEFT)
		data->shift_x -= 0.15;
	else if (keysym == S || keysym == DOWN)
		data->shift_y += 0.15;
	else if (keysym == D || keysym == RIGHT)
		data->shift_x += 0.15;
	else if (keysym == W || keysym == UP)
		data->shift_y -= 0.15;
}
void ft_color_change(t_data *data, int keysym)
{
	if (keysym == R)
		data->factor = 1;
	else if (keysym == C)
		data->factor += 1;
	else if (keysym == B && data->factor > 1)
		data->factor -= 1;
}
void ft_change_instraction(t_data *data, int keysym)
{
	if (keysym == 69)
		data->iterations += 10;
	else if (keysym == 78 && data->iterations > 10)
		data->iterations -= 10;
}

int key_handler(int keysym, void *param)
{
	t_data *data = (t_data *)param;
	if (!data)
		return 1;
	if (keysym == C || keysym == B || keysym == R)
		ft_color_change(data, keysym);
	if ((keysym >= 123 && keysym <= 126) || (keysym >= 0 && keysym <= 2) || keysym == 13)
		ft_shift_helper(data, keysym);
	if (keysym == 69 || keysym == 78)
		ft_change_instraction(data, keysym);
	fractol_render(data);
	return 0;
}

void fractol_boundries_calc(t_data *data, double offest_x, double offest_y, double zoom_factor)
{
	data->x0 = offest_x + zoom_factor * (data->x0 - offest_x);
	data->x1 = offest_x + zoom_factor * (data->x1 - offest_x);
	data->y0 = offest_y + zoom_factor * (data->y0 - offest_y);
	data->y1 = offest_y + zoom_factor * (data->y1 - offest_y);
}

int mouse_julia(int x, int y, void *param)
{
	t_data *data = (t_data *)param;
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return 1;
	double offest_x = scale(x, data->x0, data->x1, 0, WIDTH);
	double offest_y = scale(y, data->y0, data->y1, 0, HEIGHT);

	if (data->julia_move == 1)
	{
		data->x_julia = offest_x;
		data->y_julia = offest_y;
	}
	fractol_render(data);

	return 1;
}
int mouse_handler(int button, int x, int y, void *param)
{
	t_data *data = (t_data *)param;
	if (x < 0 || y < 0)
		return 1;
	double zoom_factor;

	zoom_factor = 1;
	double offest_x = scale(x, data->x0, data->x1, 0, WIDTH);
	double offest_y = scale(y, data->y0, data->y1, 0, HEIGHT);
	if (button == SCROLL_UP)
		zoom_factor = 1.2;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.8;
	if (button == 1 && !ft_strncmp(data->title, JULIA, ft_strlen(JULIA) + 1))
	{
		data->julia_move = 0;
	}
	else if (button == 2 && !ft_strncmp(data->title, JULIA, ft_strlen(JULIA) + 1))
	{
		data->julia_move = 1;
	}

	fractol_boundries_calc(data, offest_x, offest_y, zoom_factor);

	fractol_render(data);
	return 0;
}
