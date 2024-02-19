/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:13:28 by hel-asli          #+#    #+#             */
/*   Updated: 2023/11/05 03:26:42 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*d;

	len = ft_strlen(str);
	d = (char *)malloc(sizeof(char) * len +1);
	i = 0;
	if (!d)
		return (NULL);
	while (i < len)
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
