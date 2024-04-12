/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 10:51:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preparing_a(t_node **a, t_node **b)
{
	index_position(a);
	index_position(b);
	a_targets(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
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

void	set_cheapest(t_node **a)
{
	t_node	*index;
	t_node	*cheapest;
	long	min;

	init_cheapest_false(a);
	min = LONG_MAX;
	index = *a;
	while (index)
	{
		if (index->push_cost < min)
		{
			cheapest = index;
			min = index->push_cost;
		}
		index = index->next;
	}
	cheapest->cheapest = true;
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


