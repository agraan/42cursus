/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:49:25 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/03 18:50:14 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*addretval(char *retval, char *str, int len)
{
	retval = str_realloc(retval, len);
	if (!retval)
		return (NULL);
	gnl_strcat(retval, str, len);
	return (retval);
}

char	*read_line(int fd, char *stack, char *retval)
{
	int		i;
	int		count;
	char	*temp;

	while ((count = read(fd, stack, BUFFER_SIZE)) > 0)
	{
		i = -1;
		stack[count] = 0;
		while (stack[++i])
		{
			if (stack[i] == '\n')
			{
				retval = addretval(retval, stack, ft_strlen(retval) + i + 2);
				temp = ft_substr(stack, i + 1, count - i);
				gnl_strcpy(stack, temp, ft_strlen(temp) + 1);
				free(temp);
				return (retval);
			}
		}
		retval = addretval(retval, stack, ft_strlen(retval) + BUFFER_SIZE + 2);
	}
	return (retval);
}

char	*read_stack(int fd, char *stack, char *retval)
{
	char	*temp;
	int	i;
	
	i = 0;
	while (stack[i])
	{
		if (stack[i] == '\n')
			break ;
		i++;
	}
	temp = ft_substr(stack, 0, i + 1);
	retval = addretval(retval, temp, i + 1);
	free(temp);
	temp = ft_substr(stack, i, ft_strlen(stack) + 1);
	gnl_strcpy(stack, temp, ft_strlen(stack + i + 1));
	free(temp);
	if (!stack[i])
		retval = read_line(fd, stack, retval);
	return (retval);
}

char	*get_next_line(int fd)
{
	static char	stack[1024][BUFFER_SIZE];
	char		*retval;

	retval = malloc(1);
	if (!retval)
		return (NULL);
	retval[0] = 0;
	if (stack[fd][0])
		retval = read_stack(fd, stack[fd], retval);
	else
		retval = read_line(fd, stack[fd], retval);
	return (retval);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		char *temp;
		temp = get_next_line(fd);
		while (temp)
		{
			if (temp)
			{
				printf("%s", temp);
				free(temp);
			}
			temp = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
