/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:03:36 by hel-asli          #+#    #+#             */
/*   Updated: 2023/11/09 11:21:14 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*p;

	if (!f || !s)
		return (NULL);
	str = (char *)s;
	p = (char *)malloc(ft_strlen(str) + 1);
	i = 0;
	if (!p)
		return (NULL);
	while (str[i])
	{
		p[i] = f(i, str[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
