/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:54:50 by hel-asli          #+#    #+#             */
/*   Updated: 2023/11/14 05:02:35 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	void	*ptr;

	ptr = dest;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (num--)
			*((char *)dest++) = *((char *)src++);
	}
	else
	{
		while (num--)
			((char *)dest)[num] = ((char *)src)[num];
	}
	return (ptr);
}
