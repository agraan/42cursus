/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:07:27 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/06 17:08:47 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	index;

	index = 0;
	while (str[index] && !is_sep(str[index], charset))
	{
		index++;
	}
	return (index);
}

int	count_words(char *str, char *charset)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (str[index])
	{
		while (is_sep(str[index], charset) && str[index])
			index++;
		if (!is_sep(str[index], charset) && str[index])
		{
			words++;
			while (!is_sep(str[index], charset) && str[index])
				index++;
		}
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		length;
	int		temp_index;
	char	**res;

	index = 0;
	length = count_words(str, charset);
	res = malloc(sizeof(char *) * (length + 1));
	if (!res)
		return (NULL);
	while (index < length)
	{
		while (is_sep(*str, charset))
			str++;
		temp_index = 0;
		res[index] = malloc(sizeof(char) * ft_strlen(str, charset) + 1);
		if (!res[index])
			return (NULL);
		while (!is_sep(*str, charset) && *str)
			res[index][temp_index++] = *str++;
		res[index][temp_index] = 0;
		index++;
	}
	res[index] = 0;
	return (res);
}
