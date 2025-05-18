/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:30:40 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/18 21:38:30 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		exit_error(stack_a, stack_b);
	if (!parse_input(argc, argv, &stack_a))
		exit_error(stack_a, stack_b);
	//print stack a without calling another function
	t_node	*current = stack_a->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	// Uncomment the following lines when the sorting algorithm is implemented
	/*
	if (has_duplicates(stack_a))
		exit_error(stack_a, stack_b);
		
	if (stack_a->size == 2)
		sort_two(&stack_a, &stack_b);
	else if (stack_a->size == 3)
		sort_three(&stack_a, &stack_b);
	else if (stack_a->size <= 5)
		sort_five(&stack_a, &stack_b);
	else
	*/
	
	// Placeholder for sorting function
	/*
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
	*/
}
