/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:47:58 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/19 20:53:12 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int		result;
	int		i;
	int		minus;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i] == ' ' || str[i] > 9 && str[i] < 13)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != 0)
		return (0);
	return (result * minus);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
