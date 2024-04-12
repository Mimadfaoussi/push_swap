/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:31:02 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 18:49:38 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cheapest_false(t_node **a)
{
	t_node	*index;

	index = *a;
	while (index)
	{
		index->cheapest = false;
		index = index->next;
	}
}

t_node	*find_cheapest(t_node **a)
{
	t_node	*index;

	index = *a;
	while (index)
	{
		if (index->cheapest == true)
			return (index);
		index = index->next;
	}
	return (NULL);
}

int	same_direction(t_node *elm)
{
	if (elm->above_median == elm->target_node->above_median)
		return (1);
	return (0);
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
