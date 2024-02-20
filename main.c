/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:02:44 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/20 03:05:29 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	data->x0 = offest_x + zoom_factor * (data->x0 - offest_x);
	data->x1 = offest_x + zoom_factor * (data->x1 - offest_x);
	data->y0 = offest_y + zoom_factor * (data->y0 - offest_y);
	data->y1 = offest_y + zoom_factor * (data->y1 - offest_y);

	fractol_render(data);
	return 0;
}
void fractol_event_listner(t_data *data)
{
	mlx_key_hook(data->win_ptr , key_handler, data);
	mlx_mouse_hook(data->win_ptr, mouse_handler, data);
}
int main (int ac, char **av)
{
	t_data data;

	if (ac == 2 && !ft_strncmp(av[1], MANDELBROT, ft_strlen(MANDELBROT)))
	{	
		fractol_data_init(&data, av[1]);
		fractol_render(&data);
		fractol_event_listner(&data);
		mlx_loop(data.mlx_ptr);
	}
	else if (ac == 4 && !ft_strncmp(av[1], JULIA, ft_strlen(JULIA)))
	{
		printf("%s\n", JULIA);
	}
	else
	{
		ft_putstr_fd(ERROR_MASSAGE, 2);
	}
}
