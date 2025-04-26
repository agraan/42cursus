/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:43:46 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 17:45:05 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H

# define WRITE_H

void	write_zero(t_num *num);
void	write_digit(int nbr, t_num *num, int *fl);
void	write_ten(int nbr, t_num *num, int *fl);
void	write_hundred(int nbr, t_num *num, int *fl);
void	write_power(int value, t_num *num, int *fl);

#endif
