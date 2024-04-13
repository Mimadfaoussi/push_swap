/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:32:58 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 16:01:25 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	take_cheapest_up_b(t_node **a, t_node **b, t_node *cheapest)
{
	t_node	*target_node;

	target_node = cheapest->target_node;
	while (on_top(b, cheapest) == 0)
	{
		if (cheapest->above_median == true)
			rb(b);
		else
			rrb(b);
	}
	while (on_top(a, target_node) == 0)
	{
		if (target_node->above_median == true)
			ra(a);
		else
			rra(a);
	}
}


void	a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(a);
	if (same_direction(cheapest) == 1)
	{
		while (cheapest != *a && cheapest->target_node != *b)
		{
			if (cheapest->above_median)
				rr(a, b);
			else
				rrr(a, b);
		}
		take_cheapest_up(a, b, cheapest);
	}
	else
		take_cheapest_up(a, b, cheapest);
}

void	b_to_a(t_node **b, t_node **a)
{
	t_node	*cheapest;

	cheapest = find_cheapest(b);
	if (same_direction(cheapest) == 1)
	{
		while (cheapest != *b && cheapest->target_node != *a)
		{
			if (cheapest->above_median)
				rr(b, a);
			else
				rrr(b, a);
		}
		take_cheapest_up_b(a, b, cheapest);
	}
	else
	{
		take_cheapest_up_b(a, b, cheapest);
	}
}
