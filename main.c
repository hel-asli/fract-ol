/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:02:44 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/17 14:21:15 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ERROR_MASSAGE "ENTER A VALIDE FRACTOL NAME"

int main (int ac, char **av)
{
	t_data data;

	if (ac == 2 && !ft_strncmp(av[1], MANDELBROT, ft_strlen(MANDELBROT)))
	{	
		fractol_data_init(&data, av[1]);
		fractol_render(&data);
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
