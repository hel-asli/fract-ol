/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:02:16 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/19 15:30:28 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void ft_shift_helper(t_data *data, int keysym)
{
	if (keysym == A || keysym == LEFT)
		data->shift_x -= 0.75;
	else if (keysym == S || keysym == DOWN)
		data->shift_y += 0.75;
	else if (keysym == D || keysym == RIGHT)
		data->shift_x += 0.75;
	else if (keysym == W || keysym == UP)
		data->shift_y -= 0.75;
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

