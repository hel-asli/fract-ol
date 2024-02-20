/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:34:47 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/20 22:36:28 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


int is_double(char *str)
{
    int p = 0;
    char *tmp = str;
    while (*tmp)
    {
        if (*tmp == '.')
            p++;
        tmp++;
    }
    if (p > 1)
        return 0;
   while (*str)
   {
        if (*str == '.')
            str++;
        if (!(*str >= '0' && *str <= '9'))
            return 0;
        str++;
   }
    return 1;
}
int ft_check_args(char *s1, char *s2)
{
    if (is_double(s1) && is_double(s2))
    {
        return 1;
    }
    else
        return 0;
}