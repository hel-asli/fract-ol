/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:02:44 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/22 01:58:58 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void fractol_event_listner(t_data *data)
{
	mlx_hook(data->win_ptr, 02, 0, key_handler, data);
	mlx_hook(data->win_ptr, 04, 0, mouse_handler, data);
	if (ft_strncmp(data->title, JULIA, ft_strlen(JULIA)) == 0)
		mlx_hook(data->win_ptr, 06, 0, mouse_julia, data);
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
	else if (ac == 4 && !ft_strncmp(av[1], JULIA, ft_strlen(JULIA)) && ft_check_args(av[2], av[3]))
	{
		data.x_julia = ft_atodbl(av[2]);
		data.y_julia = ft_atodbl(av[3]);
		fractol_data_init(&data, av[1]);
		fractol_render(&data);
		fractol_event_listner(&data);
		mlx_loop(data.mlx_ptr);
	}
	else if (ac == 2 && !ft_strncmp(av[1], BURNINGSHIP, ft_strlen(BURNINGSHIP)))
	{
		fractol_data_init(&data, av[1]);
		fractol_render(&data);
		fractol_event_listner(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_putstr_fd(ERROR_MASSAGE, 2);
	exit(1);
}
