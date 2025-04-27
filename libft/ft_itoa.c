/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:55:47 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 21:41:08 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  nb_size(long nb, size_t i)
{
    if (nb > 9) 
        return (nb_size(nb / 10, i + 1));
    return (i);
}
char    *ft_itoa(int n)
{
    char    *str;
    long    nb;
    size_t  size;

    nb = n;
    if (n < 0)
        size = nb_size(-nb, 1);
    else
        size = nb_size(nb, 0);
    str = malloc((size + 1) * sizeof(char));
    if (!str)
        return (NULL);
    if (n < 0)
        str[0] = '-';
    str[size] = 0;
    while (--size)
    {
        str[size] = nb % size;
        nb /= 10;
    }
    return (str);
}



    

    

