/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:26:40 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/18 21:38:33 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_stack **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = (*stack)->top;
	(*stack)->top = new_node;
	(*stack)->size++;
	return (1);
}

int parse_input(int argc, char **argv, t_stack **stack_a)
{
	int i;
	int j;
	int value;

	i =	0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
		}
		value = ft_atoi(argv[i]);
		if (value > MAX_INT || value < MIN_INT)
			return (0);
		if (!add_node(stack_a, value))
			return (0);
	}
	return (1);
}
