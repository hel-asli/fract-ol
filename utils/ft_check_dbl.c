/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:34:47 by hel-asli          #+#    #+#             */
/*   Updated: 2024/02/21 02:46:23 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double ft_atodbl(char *str)
{
    double res = 0;
    long int intger = 0;
    int signe = 1;
    if (*str == '-')
    {
        signe *= -1;
        str++;
    }
    while (*str && (*str >= '0' && *str <= '9') && *str != '.')
    {
        intger *= 10;
        intger += *str - 48;
        str++;
    }
    if (*str == '.')
    {
        str++;
    }
    long int k = 1;
    long int frac = 0;
    while (*str && (*str >= '0' && *str <= '9'))
    {
        frac *= 10;
        frac += (*str - 48);
        k *= 10;
        str++;
    }
    res = intger + ((double)frac / k);

    return (res * signe);
}

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