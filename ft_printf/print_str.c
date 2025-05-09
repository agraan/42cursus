/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:30:44 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/09 19:39:26 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(t_format *f, char *s)
{
    int count;
	int	len;

	count = p->width;
	len = ft_strlen(s);
    if (!s)
        s = "(null)";
    if (!f->minus)
        write_padding(' ', p->width - len);
	if (p->dot)
		count += printf_putstr(s, p->precision);
	else
		count += ft_putstr(s);
    if (f->minus)
        write_padding(' ', p->width);
    return count;
}
