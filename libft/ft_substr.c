/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:28:55 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 17:51:45 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  size;

    size = 0;
    while (s[start + (unsigned int)size] && size < len)
        size++;
    sub = malloc(size + 1);
    if (!sub)
        return (NULL);
    return (sub);
}
