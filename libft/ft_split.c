/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:39:10 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 20:12:57 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  split_strlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)       
		i++;
	return (i);
}

static int  count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == c && s[i])
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
		}
	}
	return (words);
}

char   **malloc_split(char **arr, char *s, char c, int i;)
{
    int j;

    j = 0;
	arr[i] = malloc((split_strlen(s, c) + 1 ) * sizeof(char *));
    if (!arr[i])
        return (NULL);
	while (!(*s == c) && *s)
		arr[i][j++] = *s++;
	arr[i][j] = 0;
    return (arr);



void    free_split(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	len = count_words(s, c);
	arr = malloc((len + 1) * sizeof(char *));
    if (!arr)
        return (NULL);
	while (i < len)
	{
		while (*s == c)
			s++;
        if (!malloc_split(arr, s, c, i))
        {
            free_split(arr);
            return (NULL);
        }
		i++;
	}
	arr[i] = 0;
	return (arr);
}
