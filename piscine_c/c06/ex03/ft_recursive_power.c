/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:24:48 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/19 19:25:19 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
/*#include <stdio.h>

int ft_recursive_power(int nb, int power);

int	main(void)
{
	printf("0:%d\n", ft_recursive_power(1, -10));
	printf("0:%d\n", ft_recursive_power(1, -1));
	printf("1:%d\n", ft_recursive_power(10, 0));
	printf("10:%d\n", ft_recursive_power(10, 1));
	printf("100:%d\n", ft_recursive_power(10, 2));
	printf("216:%d\n", ft_recursive_power(6, 3));
}
*/
