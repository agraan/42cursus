/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:33:31 by raamayri          #+#    #+#             */
/*   Updated: 2025/02/02 19:32:55 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	step56(char *str, int step, int i)
{
	if (step == 5 && str[i] >= 32 && str[i] < 127)
	{
		if (str[i + 1] == '\n')
			return (6);
		else if (!(str[i + 1] >= 32 && str[i + 1] < 127))
			return (-1);
	}
	else if (step == 6 && str[i] == '\n')
	{
		if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == 32)
			return (1);
		else if (!str[i + 1])
			return (0);
	}
	else if (step == 5 || step == 6)
	{
		return (-1);
	}
	return (0);
}

int	step34(char *str, int step, int i)
{
	if (step == 3 && str[i] == ':')
	{
		if (str[i + 1] == 32)
			return (4);
		else if (str[i + 1] > 32 && str[i + 1] < 127)
			return (5);
		return (-1);
	}
	else if (step == 4 && str[i] == 32)
	{
		if (str[i + 1] >= 32 && str[i + 1] < 127)
			return (5);
		else if (!(str[i + 1] == 32))
			return (-1);
	}
	else if (step == 3 || step == 4)
	{
		return (-1);
	}
	return (0);
}

int	step12(char *str, int step, int i)
{
	if (step == 1 && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i + 1] == 32)
			return (2);
		else if (str[i + 1] == ':')
			return (3);
		else if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (-1);
	}
	else if (step == 1 && str[i] == 32)
	{
		return (1);
	}
	else if (step == 2 && str[i] == 32)
	{
		if (str[i + 1] == ':')
			return (3);
		else if (!(str[i + 1] == 32))
			return (-1);
	}
	else if (step == 1 || step == 2)
	{
		return (-1);
	}
	return (0);
}

int	is_valid_dict(char *str)
{
	int	i;
	int	step;

	i = 0;
	step = 1;
	while (str[i])
	{
		if (step12(str, step, i) == -1)
			return (0);
		if (step34(str, step, i) == -1)
			return (0);
		if (step56(str, step, i) == -1)
			return (0);
		if (step12(str, step, i) > 0)
			step = step12(str, step, i);
		if (step34(str, step, i) > 0)
			step = step34(str, step, i);
		if (step56(str, step, i) > 0)
			step = step56(str, step, i);
		i++;
	}
	return (1);
}

int	is_valid_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
