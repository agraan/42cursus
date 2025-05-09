/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:50:26 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:22 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const	char *str, ...)
{
	va_list		args;
	t_params	p;
	int			i;

	i = 0;
	va_start(args, str);
	while(*str)
	{
		if(*str == '%')
			i += params_handler(parse_flags(&str, args);
		else
			i += write(1, str, 1);
	}
	return (i);
}
