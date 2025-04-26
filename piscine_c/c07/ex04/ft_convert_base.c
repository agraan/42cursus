/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:24:53 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/01 23:29:28 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int				base_correct(const char *base, int base_len);
int				ft_base_len(const char *base);
void			ft_putnbr_base(long nbr, const char *base, char *str, int *i);
int				in_base(char c, const char *base);

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

long	ft_atoi_base(const char *str, const char *base)
{
	long	result;
	int		i;
	int		minus;
	int		len;

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

int	test_bases(char *base_from, char *base_to)
{
	if (!(base_correct(base_from, ft_base_len(base_from))))
		return (1);
	if (*base_from == 0)
		return (1);
	if (!(base_correct(base_to, ft_base_len(base_to))))
		return (1);
	if (*base_to == 0)
		return (1);
	return (0);
}

int	nblen(int nb, int baselen)
{
	int	len;

	len = 0;
	while (nb > baselen)
	{
		len++;
		nb /= baselen;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	long	atoi;
	int		len;
	int		i;

	if (test_bases(base_from, base_to))
		return (NULL);
	atoi = ft_atoi_base(nbr, base_from);
	len = nblen(atoi, ft_base_len(base_to));
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to, str, &i);
	str[i] = 0;
	return (str);
}
