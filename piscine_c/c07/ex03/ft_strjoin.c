/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:55:01 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/06 12:55:05 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ultimate_strlen(char **str, int size)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (i < size)
	{
		result += ft_strlen(str[i]);
		i++;
	}
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = ft_strlen(dest);
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		len;

	len = (ft_ultimate_strlen(strs, size) + (ft_strlen(sep)
				* (size - 1 + (size == 0))));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	i = -1;
	while (++i < size)
	{
		ft_strcat(str, strs[i]);
		if (i != size - 1)
			ft_strcat(str, sep);
	}
	str[len] = 0;
	return (str);
}
