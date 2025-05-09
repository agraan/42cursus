/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:55:45 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/09 19:07:28 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_params
{
    int		width;
    int     precision;
    int     zero;
    int     minus;
    int     hash;
    int     plus;
    int     space;
    char    type;
}				t_params;

void	write_padding(char c, int len);

int	ft_isdigit(char c);
int	ft_atoi(const char *str);
int	is_flags(char c);

int print_char(t_params *p, char c);
#endif
