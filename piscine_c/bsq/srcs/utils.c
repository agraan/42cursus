/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:52:37 by babodere          #+#    #+#             */
/*   Updated: 2025/02/04 15:09:46 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_strerr(char *err)
{
	int	index;

	index = 0;
	while (err[index])
		index++;
	write(2, err, index);
}

int	is_char_correct(char c)
{
	return (!(c < 32 || c == 127));
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_atoi(char *str)
{
	int	result;
	int	signe;

	result = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			signe *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str++ - '0') * signe;
	}
	return (result);
}
