/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/11 16:51:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_sort_3(t_node **a)
{
	t_node	*index;

	index = find_biggest(a);
	if (index == *a)
		ra(a);
	else if (index == (*a)->next)
		rra(a);
	if (!sorted_stack(*a))
		sa(a);
}

void	stack_sort(t_node **a, t_node **b)
{

	pb(b, a);
	if (stack_length(*a) > 3 && !sorted_stack(*a))
		pb(b, a);
	// while (stack_length(*a) > 3 && !sorted_stack(*a))
	// {
	// 	preparing_a(a, b);
	// 	//a_to_b(a, b);
	// 	pb(b, a);
	// }
	preparing_a(a, b);
	// stack_sort_3(a);
	// while (*b)
	// {
	// 	// preparing_b(b, a);
	// 	// b_to_a(b, a);
	// 	pa(a, b);
	// }
}
