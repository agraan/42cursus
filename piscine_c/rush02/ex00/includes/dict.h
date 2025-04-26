/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 06:14:45 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 22:37:00 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H

# define DICT_H
# define BUFF_SIZE 4096
# include <unistd.h>

typedef struct numbers
{
	char	*key;
	char	*value;
}			t_num;

void	read_file(char *file);
int		count_bytes(char *file);
char	*save_file(char *file, int bytes);
int		ft_strlen(char *str);

#endif
