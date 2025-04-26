/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:02:24 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/26 20:42:19 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IS_VALID_H
# define IS_VALID_H

int	is_cell_valid(int map[4][4], int row, int col);
int	is_map_valid(int skycraper[4][4], int map[4][4], int row, int col);
#endif
