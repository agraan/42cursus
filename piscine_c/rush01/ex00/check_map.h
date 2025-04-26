/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:06:04 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/26 20:20:42 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECK_MAP_H
# define CHECK_MAP_H

int	check_col_top(int map[4][4], int col, int num);
int	check_col_down(int map[4][4], int col, int num);
int	check_row_left(int map[4][4], int row, int num);
int	check_row_right(int map[4][4], int row, int num);
#endif
