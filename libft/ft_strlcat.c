/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:17:01 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 18:30:10 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    int     j;

    i = ft_strlen(dst);
    j = 0;
    while (i < size)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = 0;
    return (i);
}
