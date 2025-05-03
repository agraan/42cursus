/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:45:51 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/03 16:36:48 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_realloc(char *str, size_t size)
{
	char	*new;

	new = malloc(size + 1);
	if (!new)
		return (free(str), NULL);
	gnl_strcpy(new, str, size);
	return (free(str), new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	//printf("string = |%s|\n", str);
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	gnl_strcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

void	gnl_strcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	int		i;

	len_dst = ft_strlen(dst);
	if (!size)
		return ;
	i = 0;
	while (src[i] && i + len_dst < size - 1)
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = 0;
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	len_s;

	size = 0;
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	while ((size_t)start + size < len_s && size < len)
		size++;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = s[start + size];
	return (sub);
}
