/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:44:00 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 18:20:55 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_in_charset(char c, char *charset);

void	copy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	dest[i] = 0;
}

int	split_str(char *str, char *charset, char **arr, int words)
{
	int	i;
	int	k;

	i = 0;
	while (i < words)
	{
		while (*str && (is_in_charset(*str, charset) || *str == 32))
			str++;
		k = 0;
		while (str[k] && !(is_in_charset(str[k], charset)))
			k++;
		arr[i] = malloc(k + 1);
		if (arr[i] == NULL)
			return (0);
		k = 0;
		while (*str && !(is_in_charset(*str, charset) && *str != 32))
			arr[i][k++] = *str++;
		arr[i][k] = 0;
		i++;
	}
	return (1);
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	if (*str == 0)
		return (0);
	while (str[++i])
	{
		if (is_in_charset(str[i], charset) && i > 0)
			if (!(is_in_charset(str[i - 1], charset)))
				count++;
	}
	if (str[i] == 0 && !(is_in_charset(str[i - 1], charset)))
		count++;
	return (count);
}

char	**ft_split(char *str, char *charset, char **dict)
{
	int		words;

	words = count_words(str, charset);
	if (*charset == 0)
		dict[0] = str;
	else
		split_str(str, charset, dict, words);
	dict[words] = 0;
	return (dict);
}
