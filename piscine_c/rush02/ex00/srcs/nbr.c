/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 06:38:33 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 06:45:37 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (i++ % 3 == 0)
			res++;
	}
	return (res);
}

void	ft_setnbr(int *nbr, char *str)
{
	int	i;
	int	to;

	i = 0;
	while (str[i])
		i++;
	to = 3;
	if (i % 3 != 0)
		to = i % 3;
	i = 0;
	nbr[0] = 0;
	while (str[i] && i < to)
		nbr[0] = nbr[0] * 10 + (str[i++] - 48);
	if (str[i] >= '0' && str[i] <= '9')
		ft_setnbr(&nbr[1], &str[i]);
}

void	ft_revnbr(int *nbr, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		tmp = nbr[i];
		nbr[i] = nbr[size - 1 - i];
		nbr[size - 1 - i] = tmp;
		i++;
	}
}
