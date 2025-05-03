/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:49:25 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/03 16:57:15 by aprigent         ###   ########.fr       */
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
		while (stack[++i])
		{
			stack[BUFFER_SIZE] = 0;
			if (stack[i] == '\n')
			{
				retval = addretval(retval, stack, ft_strlen(retval) + i + 2);
				temp = ft_substr(stack, i + 1, count - i);
				gnl_strcpy(stack, temp, ft_strlen(temp));
				free(temp);
				//printf("stack = %s\n", stack);
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
	temp = ft_substr(stack, i + 1, ft_strlen(stack) + 1);
	gnl_strcpy(stack, temp, ft_strlen(stack) - i);
	free(temp);
	if (!stack[i])
		read_line(fd, stack, retval);
	return (retval);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*retval;

	retval = malloc(1);
	stack[fd] = NULL;
	if (BUFFER_SIZE >= 0)
		stack[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!retval || stack[fd])
		return (NULL);
	retval[0] = 0;
	if (stack[fd][0])
		retval = read_stack(fd, stack[fd], retval);
	else
		retval = read_line(fd, stack[fd], retval);
	if (!retval)
		return (free(retval), NULL);
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
		printf("%s", temp = get_next_line(fd));
		free(temp);
		printf("%s", temp = get_next_line(fd));
		free(temp);
		close(fd);
	}
	return (0);
}
