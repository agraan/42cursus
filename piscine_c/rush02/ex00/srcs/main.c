/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:22:06 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 23:26:27 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "dict.h"

void	start(char *dict, char *input, int i);
int		is_valid_arg(char *str);
int		is_valid_dict(char *str);

int	check_dict(char *dict)
{
	if (is_valid_dict(save_file(dict, count_bytes(dict))))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && check_dict("dicts/en.dict"))
	{
		if (is_valid_arg(argv[1]))
			start("dicts/en.dict", argv[1], 0);
		else
			return (write(1, "Error\n", 6), 0);
	}
	else if (argc == 3 && check_dict(argv[1]))
	{
		if (is_valid_arg(argv[2]))
			start(argv[1], argv[2], 0);
		else
			return (write(1, "Error\n", 6), 0);
	}
	else
		return (write(1, "Dict Error\n", 11), 0);
	return (0);
}
