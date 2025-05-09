/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:08:51 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/09 18:09:37 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_rest(const char **str, t_params *p)
{
	if (ft_isdigit(**str))
		p->width = ft_atoi(*str);
	if (**str == '.')
	{
		p->dot += 1;
		*str++;
		p->precision = ft_atoi(*str);
	}
	if (is_type(**str))
		p->type = **str;
}

t_params	parse_flags(const char **str)
{
	t_params	p;

	init_struct(p);
	while (is_flag(**str))
	{
		if (**str == '#')
			p.hash += 1;
        if (**str == '0')
			p.zero += 1;
        if (**str == '-')
			p.minus += 1;
        if (**str == '+')
			p.plus += 1;
        if (**str == ' ')
			p.space += 1;
		(*str)++;
	}
	parse_rest(*str, p);
	return (p);
}
