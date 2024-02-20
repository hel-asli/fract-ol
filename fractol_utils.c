/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:11:32 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/20 05:09:49 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void ft_putstr_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);

	while ((*s1 || *s2) && *s1 == *s2 && n >= 0)
	{
		s1++;
		s2++;
		n--;
	}

	return (*s1 - *s2);
}
