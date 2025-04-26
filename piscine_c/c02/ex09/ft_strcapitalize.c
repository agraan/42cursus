/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:33:38 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/16 22:04:44 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isnt_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (0);
	else if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	i++;
	while (str[i] != 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (isnt_alphanum(str[i - 1]))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
