/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:02:44 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/18 05:57:07 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ERROR_MASSAGE "ENTER A VALIDE FRACTOL NAME"

int key_handler(int keysym, t_data *data)
{
	if (!data)
		return 1;
	if (keysym == 69)
	{
		data->factor += 69;
		fractol_render(data);
	}
	return 0;
}
void fractol_event_listner(t_data *data)
{
	mlx_key_hook(data->win_ptr , key_handler, data);
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
