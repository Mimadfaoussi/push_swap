/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/10 06:36:11 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preparing_a(t_node **a, t_node **b)
{
	index_position(a);
	index_position(b);
	a_targets(a, b);
	//set_cost_a(a, b);
	//set_cheapest(a);
}

void	index_position(t_node **stack)
{
	t_node	*index;
	int		i;
	int		middle;

	if (!*stack)
		return ;
	index = *stack;
	middle = stack_length(*stack) / 2;
	i = 0;
	while (index)
	{
		if (i <= middle)
			index->above_median = true;
		else
			index->above_median = false;
		index->index = i;
		index = index->next;
		i++;
	}
}

/**
ia = index a
ib = index b
b_s = closest smaller number
*/
void	a_targets(t_node **a, t_node **b)
{
	t_node	*target;
	long	b_s;
	t_node	*ia;
	t_node	*ib;

	ia = *a;
	while (ia)
	{
		b_s = LONG_MIN;
		ib = *b;
		while (ib)
		{
			if (ib->value < ia->value && ib->value > b_s)
			{
				b_s = ib->value;
				target = ib;
			}
			ib = ib->next;
		}
		if (b_s == LONG_MIN)
			ia->target_node = find_biggest(b);
		else
			ia->target_node = target;
		ia = ia->next;
	}
}

void	set_cost_a(t_node **a, t_node **b)
{
	t_node	*index_a;
	t_node	*index_b;
	int		push_cost;

	index_a = *a;
	index_b = *b;
	while (index_a)
	{
		push_cost = index_a->index;
		if (index_a->above_median == false)
			push_cost = stack_length(*a) - index_a->index;
		if ((index_a->target_node)->above_median == false)
			push_cost = push_cost + stack_length(*b) - (index_a->target_node)->index;
		else
			push_cost = push_cost + (index_a->target_node)->index;
		index_a->push_cost = push_cost;
		index_a = index_a->next;
	}
}
