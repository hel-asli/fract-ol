/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:34:47 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/27 20:30:19 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

long int	ft_frac(char *str, long int *k)
{
	long int	frac;

	frac = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		frac = frac * 10 + (*str++ - 48);
		*k = *k * 10;
	}
	return (frac);
}

double	ft_atodbl(char *str)
{
	long int	intger;
	long int	k;
	long int	frac;
	int			signe;

	intger = 0;
	signe = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9') && *str != '.')
		intger = intger * 10 + (*str++ - 48);
	if (*str == '.')
		str++;
	k = 1;
	frac = ft_frac(str, &k);
	return ((intger + ((double)frac / k)) * signe);
}

int	point_count(char *tmp)
{
	int	p;

	p = 0;
	if (*tmp == '.' && !*(tmp+1))
		return (2);
	while (*tmp)
	{
		if (*tmp == '.')
			p++;
		tmp++;
	}
	return (p);
}

int	is_double(char *str)
{
	int		p;

	p = point_count(str);
	if (p > 1)
		return (0);
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			break ;
		str++;
	}
	while (*str)
	{
		if (!((*str >= 8 && *str <= 13) || *str == 32))
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_args(char *s1, char *s2)
{
	if ((*s1 && *s2) && (is_double(s1) && is_double(s2)))
		return (1);
	else
		return (0);
}
