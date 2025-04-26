/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:57:56 by babodere          #+#    #+#             */
/*   Updated: 2025/02/05 22:41:14 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	correct_chars(char a, char b, char c)
{
	if (a == b)
		return (0);
	if (b == c)
		return (0);
	if (a == c)
		return (0);
	return (1);
}

int	map_correct(char *file, char empty, char obstacle)
{
	int		i;
	int		fd;
	char	buff[BUFF_SIZE];

	fd = open(file, O_RDONLY);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		i = 0;
		while (i < BUFF_SIZE)
		{
			if (buff[i++] == '\n')
				break ;
		}
		while (i < BUFF_SIZE && buff[i])
		{
			if (buff[i] != empty && buff[i] != obstacle && buff[i] != '\n')
				return (0);
			i++;
		}
	}
	return (1);
}
