/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:11:34 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/22 15:32:36 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	double	heron;
	double	next;
	int		precision;

	precision = 0;
	heron = nb;
	next = 0;
	while (precision++ < 20)
	{
		next = (heron + nb / heron) / 2;
		heron = next;
	}
	if (nb != (int)heron * (int)heron)
		return (0);
	return (heron);
}
