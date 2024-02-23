/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:34:47 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/22 23:50:11 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atodbl(char *str)
{
	long int	intger;
	long int	k;
	long int	frac;
	int			signe;

	intger = 0;
	signe = 1;
	if (*str == '-')
	{
		signe *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9') && *str != '.')
		intger = intger * 10 + (*str++ - 48);
	if (*str == '.')
		str++;
	k = 1;
	frac = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		frac = frac * 10 + (*str++ - 48);
		k *= 10;
	}
	return ((intger + ((double)frac / k)) * signe);
}

int	is_double(char *str)
{
	int		p;
	char	*tmp;

	p = 0;
	tmp = str;
	while (*tmp)
	{
		if (*tmp == '.')
			p++;
		tmp++;
	}
	if (p > 1)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_args(char *s1, char *s2)
{
	if (is_double(s1) && is_double(s2))
		return (1);
	else
		return (0);
}
