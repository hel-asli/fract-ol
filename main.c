/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:02:44 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/26 16:58:08 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_demantion(int width, int height)
{
	return (width > 0 && height > 0 && width <= 2000 && height <= 1500);
}

int	destroy_helper(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	exit(EXIT_SUCCESS);
	return (0);
}

void	fractol_event_listner(t_data *data)
{
	mlx_hook(data->win_ptr, 02, 0, key_handler, data);
	mlx_hook(data->win_ptr, 04, 0, mouse_handler, data);
	if (!ft_strcmp(data->title, JULIA) && data->julia_move)
		mlx_hook(data->win_ptr, 06, 0, mouse_julia, data);
	mlx_hook(data->win_ptr, 17, 0, destroy_helper, data);
}

void	fractol_helper(t_data *data, char **av)
{
	fractol_data_init(data, av[1]);
	fractol_render(data);
	fractol_event_listner(data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_demantion(WIDTH, HEIGHT))
	{
		ft_putstr_fd("WIDTH && HEIGHT need to be greater than 0\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ac == 2 && !ft_strcmp(av[1], MANDELBROT))
		fractol_helper(&data, av);
	else if (ac == 4 && !ft_strcmp(av[1], JULIA)
		&& ft_check_args(av[2], av[3]))
	{
		data.x_julia = ft_atodbl(av[2]);
		data.y_julia = ft_atodbl(av[3]);
		fractol_helper(&data, av);
	}
	else if (ac == 2 && !ft_strcmp(av[1], BURNINGSHIP))
		fractol_helper(&data, av);
	else
	{
		ft_putstr_fd(ERROR_MASSAGE, 2);
		exit(EXIT_FAILURE);
	}
}
