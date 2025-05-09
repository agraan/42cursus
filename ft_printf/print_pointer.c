/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:46:44 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/09 19:37:38 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(t_format *f, void *ptr)
{
    unsigned long	addr;
    int				count;
    char			*str;
	int				len;
    
	addr = (unsigned long)ptr;
    str = itoa_hex_low(addr);
    len = ft_strlen(str);
	count = p->width;
    if (!p->minus && !p->zero)
        write_padding(' ', p->width - (2 + len));
    write(1, "0x", 2);
    count += write(1, str, len);
    if (p->minus)
        write_padding(' ', p->width - (2 + len));
    free(str);
    return count;
}

