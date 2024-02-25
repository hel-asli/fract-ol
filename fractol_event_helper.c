/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:58:54 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/25 00:10:25 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_close_window(t_data *data)
{
	if (!data)
		return ;
	// mlx_destroy_image(data->mlx_ptr, data->img.img);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// free(data->mlx_ptr);
	// free(data->title);
	exit(EXIT_SUCCESS);
}

void	ft_shift_helper(t_data *data, int keysym)
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

void	ft_color_change(t_data *data, int keysym)
{
	if (keysym == R)
		data->factor = 1;
	else if (keysym == C)
		data->factor += 1;
	else if (keysym == B && data->factor > 1)
		data->factor -= 1;
}

void	ft_change_instraction(t_data *data, int keysym)
{
	if (keysym == 69)
		data->iterations += 10;
	else if (keysym == 78 && data->iterations > 10)
		data->iterations -= 10;
}

int	key_handler(int keysym, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data)
		return (1);
	if (keysym == C || keysym == B || keysym == R)
		ft_color_change(data, keysym);
	if ((keysym >= 123 && keysym <= 126)
		|| (keysym >= 0 && keysym <= 2) || keysym == 13)
		ft_shift_helper(data, keysym);
	if (keysym == 69 || keysym == 78)
		ft_change_instraction(data, keysym);
	if (keysym == ESC)
		ft_close_window(data);
	fractol_render(data);
	return (0);
}
