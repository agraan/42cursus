/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:33:23 by babodere          #+#    #+#             */
/*   Updated: 2025/02/05 21:32:25 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# define FT_H
# define BUFF_SIZE 10000
# define TRUE 1
# define FALSE 0
# define FILE_NAME "map.txt"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	int		lines;
	int		len;
	char	empty;
	char	full;
	char	obstacle;
}	t_map;

typedef struct s_max
{
	int	val;
	int	line;
	int	i;
	int	fd;
}	t_max;

typedef int	t_bool;

int		correct_chars(char a, char b, char c);
int		file_correct(char *file);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		is_char_correct(char c);
int		count_bytes(int fd);
int		map_correct(char *file, char empty, char obstacle);
void	ft_strerr(char *err);
void	solve_map(char *file);
void	ft_putstr(char *str);
t_map	get_struct(char *file);
char	*get_next_line(int fd, int line_len);
t_max	solve(int **arr, t_map map, char *file, t_max max);
void	print_map(char *file, t_map map, t_max max);
char	*save_file(char *file, int bytes);

#endif
