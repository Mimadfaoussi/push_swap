/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:46:58 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 16:02:42 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
* find_biggest- search the stack and return the node with biggest value
**/

t_node	*find_biggest(t_node **a)
{
	t_node	*biggest;
	t_node	*index;

	if (!*a)
		return (NULL);
	biggest = *a;
	index = *a;
	while (index)
	{
		if (index->value > biggest->value)
			biggest = index;
		index = index->next;
	}
	return (biggest);
}

/**
* find_smallest- search the stack and return the node with biggest value
**/

t_node	*find_smallest(t_node **stack)
{
	t_node	*smallest;
	t_node	*index;

	if (!*stack)
		return (NULL);
	smallest = *stack;
	index = *stack;
	while (index)
	{
		if (index->value < smallest->value)
			smallest = index;
		index = index->next;
	}
	return (smallest);
}

/**
* sorted_stack - check if the stack is sorted
**/

bool	sorted_stack(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

/**
* stack_length - function that calculate and return the length of the stack
**/

int	stack_length(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/**
* take_smallest_up-after finishing ordering the stack we need to make sure 
* that the smallest is on top 
**/

void	take_smallest_up(t_node **a, t_node *smallest)
{
	while (on_top(a, smallest) == 0)
	{
		if (smallest->above_median == true)
			ra(a);
		else
			rra(a);
	}
}
