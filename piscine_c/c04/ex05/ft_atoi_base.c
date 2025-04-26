/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:08:07 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/20 21:30:12 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_correct(const char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len == 0 || base_len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

unsigned int	ft_base_len(const char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	in_base(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	result;
	int	i;
	int	minus;
	int	len;

	len = ft_base_len(base);
	if (!(base_correct(base, len)))
		return (0);
	i = 0;
	minus = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] && in_base(str[i], base) >= 0)
		result = result * len + in_base(str[i++], base);
	return (result * minus);
}
