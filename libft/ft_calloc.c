/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:04:32 by hel-asli          #+#    #+#             */
/*   Updated: 2023/11/22 19:08:05 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t size_element)
{
	void	*tab;
	long	nb;
	long	size;

	nb = num_elements;
	size = size_element;
	if (nb < 0 && size < 0)
		return (NULL);
	tab = malloc(num_elements * size_element);
	if (tab)
		ft_bzero (tab, num_elements * size_element);
	return (tab);
}
