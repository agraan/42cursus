/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:58:46 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/31 21:49:39 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	i = min;
	j = 0;
	if (min >= max)
		return (0);
	(*range) = (int *) malloc((max - min) * sizeof(int));
	if ((*range) == NULL)
		return (-1);
	while (i < max)
	{
		(*range)[i - min] = i;
		i++;
	}
	return (max - min);
}
