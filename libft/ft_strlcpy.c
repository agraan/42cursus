/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:13:38 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 18:16:54 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;

    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (i);
}
