/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:31:34 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 18:57:01 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(const char *s1, const char *set)
{
    char    *str;
    int     i;
    int     j;
    int     len;

    i = 0;
    len = ft_strlen(s1) - 1;
    j = ft_strlen(set) - 1;
    while (s1[i] == set[i])
        i++;
    while (s1[len] == set[j])
    {
        j--;
        len--;
    }
    str = malloc(len - i + 1);
    if (!str)
        return (NULL);
    j = 0;
    while (i <= len)
        str[j++] = s1[i++];
    return (str)
}

