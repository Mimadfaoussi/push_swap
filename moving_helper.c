/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:32:58 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 15:33:45 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
* on_top-checks that the element is on the top of the stack
*
**/
int	on_top(t_node **stack, t_node *elm)
{
	if (elm == *stack)
		return (1);
	return (0);
}

/***
* get_common_steps - function that will get the common rotations 
* which is the smallest number in between
**/
int	get_common_steps(t_node *a, t_node *b, t_node *elm)
{
	if (elm->index < elm->target_node->index)
	{
		if (elm->above_median == true)
			return (elm->index);
		else
			return (stack_length(a) - elm->index);
	}
	else
	{
		if (elm->above_median == true)
			return (elm->target_node->index);
		else
			return (stack_length(b) - elm->target_node->index);
	}
}

void	take_cheapest_up(t_node **a, t_node **b, t_node *cheapest)
{
	t_node	*target_node;

	target_node = cheapest->target_node;
	while (on_top(a, cheapest) == 0)
	{
		if (cheapest->above_median == true)
			ra(a);
		else
			rra(a);
	}
	while (on_top(b, target_node) == 0)
	{
		if (target_node->above_median == true)
			rb(b);
		else
			rrb(b);
	}
}

void	a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int		nb;
	int		i;

	i = 0;
	cheapest = find_cheapest(a);
	if (same_direction(cheapest) == 1)
	{
		nb = get_common_steps(*a, *b, cheapest);
		while (i < nb)
		{
			if (cheapest->above_median)
				rr(a, b);
			else
				rrr(a, b);
			i++;
		}
		take_cheapest_up(a, b, cheapest);
	}
	else
		take_cheapest_up(a, b, cheapest);
}
