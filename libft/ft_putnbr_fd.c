/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:15:34 by aprigent          #+#    #+#             */
/*   Updated: 2025/04/26 22:19:38 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    long    nb;

    nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-');
		nb = -nb;
	}
	if (nb > 9)	
    {
		ft_putnbr_fd(nb / 10);
		ft_putchar_fd(nb % 10 + 48);
	}
	else
		ft_putchar_fd(nb + 48);
	}
}
