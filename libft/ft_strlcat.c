/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:43:01 by hel-asli          #+#    #+#             */
/*   Updated: 2023/11/04 23:56:07 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	char	*buff_dst;
	size_t	space_left;

	src_len = ft_strlen(src);
	if (dstsize == 0 && !dst)
		return (src_len);
	dst_len = ft_strlen(dst);
	buff_dst = dst + dst_len;
	space_left = dstsize - dst_len - 1;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (*src && space_left > 0)
	{
		*buff_dst++ = *src++;
		space_left--;
	}
	*buff_dst = '\0';
	return (dst_len + src_len);
}
