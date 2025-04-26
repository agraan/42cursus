/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:56:08 by raamayri          #+#    #+#             */
/*   Updated: 2025/02/02 22:29:45 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "nbr.h"

void	rm_space2(t_num *num, int k)
{
	int	i;
	int	j;
	int	fl;

	i = -1;
	fl = 0;
	while (num[++i].value)
	{
		j = -1;
		k = 0;
		while (num[i].value[++j])
		{
			if (num[i].value[j] != 32)
			{
				fl = 1;
				num[i].value[k++] = num[i].value[j];
			}
			else if (fl == 1)
			{
				fl = 0;
				num[i].value[k++] = num[i].value[j];
			}
		}
		num[i].value[k] = 0;
	}
}

void	rm_space(t_num *num)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (num[++i].key)
	{
		j = -1;
		k = 0;
		while (num[i].key[++j])
		{
			if (num[i].key[j] != 32)
				num[i].key[k++] = num[i].key[j];
		}
	}
	rm_space2(num, 0);
}
