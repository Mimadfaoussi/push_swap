/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:28:14 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 15:58:22 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	preparing_b(t_node **b, t_node **a)
{
	index_position(a);
	index_position(b);
	b_targets(b, a);
	set_cost_b(b, a);
	set_cheapest(b);
}

void	b_targets(t_node **b, t_node **a)
{
	t_node	*target;
	long	b_s;
	t_node	*ia;
	t_node	*ib;

	ib = *b;
	while (ib)
	{
		b_s = LONG_MAX;
		ia = *a;
		while (ia)
		{
			if (ia->value > ib->value && ia->value < b_s)
			{
				b_s = ia->value;
				target = ia;
			}
			ia = ia->next;
		}
		if (b_s == LONG_MAX)
			ib->target_node = find_smallest(a);
		else
			ib->target_node = target;
		ib = ib->next;
	}
}



void	set_cost_b(t_node **b, t_node **a)
{
	t_node	*index_a;
	t_node	*index_b;
	int		push_cost;

	index_a = *a;
	index_b = *b;
	while (index_b)
	{
		push_cost = index_b->index;
		if (index_b->above_median == false)
			push_cost = stack_length(*b) - index_b->index;
		if ((index_b->target_node)->above_median == false)
		{
			push_cost = push_cost + stack_length(*a);
			push_cost = push_cost - (index_b->target_node)->index;
		}
		else
			push_cost = push_cost + (index_b->target_node)->index;
		index_b->push_cost = push_cost;
		index_b = index_b->next;
	}
}
