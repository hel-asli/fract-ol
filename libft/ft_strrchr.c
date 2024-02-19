/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:44:10 by hel-asli          #+#    #+#             */
/*   Updated: 2023/11/08 10:09:44 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	size_t			len;

	if (!*s && c == 0)
		return ((char *)s);
	len = ft_strlen(s) + 1;
	a = (unsigned char)c;
	while (len--) 
	{
		if (*(s + len) == a)
			return ((char *)s + len);
	}
	return (NULL);
}
