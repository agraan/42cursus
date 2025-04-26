/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:46 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 17:06:55 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;

    if (!nmemb || !size || nmemb > ((size_t) - 1) / size)l
        return ((void *)malloc(0));
    ptr = (void *)malloc(nmemb * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, size);
    return (ptr);
}
