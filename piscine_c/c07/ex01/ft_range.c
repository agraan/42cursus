/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:18:20 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/27 18:43:43 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	i = min;
	if (min >= max)
		return (NULL);
	tab = (int *) malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (i < max)
	{
		tab[i - min] = i;
		i++;
	}
	return (tab);
}
