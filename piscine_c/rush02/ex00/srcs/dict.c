/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 06:12:39 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 23:06:00 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "dict.h"
#include <fcntl.h>
#include "nbr.h"

char	**ft_split(char *str, char *charset, char **dict);
int		*algo(int *nbr, int len, t_num *num);
int		count_words(char *str, char *charset);
void	rm_space(t_num *num);
void	free_value(char **dict_value, t_num *num);

int	count_bytes(char *file)
{
	char	buff[BUFF_SIZE];
	int		n;
	int		fd;
	int		size;

	fd = open(file, O_RDONLY);
	size = 0;
	while (1)
	{
		n = read(fd, buff, BUFF_SIZE);
		if (n <= 0)
			break ;
		size += n;
	}
	close(fd);
	return (size);
}

char	*save_file(char *file, int bytes)
{
	char	*retval;
	char	buff[1];
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	retval = (char *) malloc(sizeof(char) * (bytes + 1));
	while (read(fd, buff, 1) > 0)
	{
		retval[i++] = buff[0];
	}
	retval[i] = '\0';
	close(fd);
	return (retval);
}

int	*create_nbr(char *input)
{
	int	*nbr;
	int	len;

	len = ft_nbrlen(input);
	nbr = malloc(sizeof(int *) * len + 1);
	if (!nbr)
		return (write(1, "Error\n", 6), NULL);
	ft_setnbr(nbr, input);
	ft_revnbr(nbr, len);
	return (nbr);
}

int	start(char *dict, char *input, int i)
{
	char	**dict_value;
	int		words;
	int		j;
	t_num	*num;	

	words = count_words(save_file(dict, count_bytes(dict)), ":\n");
	dict_value = malloc(sizeof(char *) * (words + 1));
	if (!dict_value)
		return (write(1, "Error\n", 6), 0);
	ft_split(save_file(dict, count_bytes(dict)), ":\n", dict_value);
	j = 0;
	num = malloc(sizeof(t_num) * (words + 1) / 2 + 1);
	if (!num)
		return (write(1, "Error\n", 6), 0);
	while (dict_value[i])
	{
		num[j].key = dict_value[i];
		num[j++].value = dict_value[i + 1];
		i += 2;
	}
	num[j].value = 0;
	rm_space(num);
	free(algo(create_nbr(input), ft_nbrlen(input), num));
	return (free_value(dict_value, num), 0);
}
