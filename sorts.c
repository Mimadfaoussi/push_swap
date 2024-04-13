/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 15:47:35 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
* stack_sort_3 - takes a stack with 3 values and order it by 
* sending the biggest to the last and swaping first two if it needs to
**/

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

/**
* stack_sort - sorts the stack that contain more than 3 elements using 
* the turc algorithme .
**/

void	stack_sort(t_node **a, t_node **b)
{
	pb(b, a);
	if (stack_length(*a) > 3 && !sorted_stack(*a))
		pb(b, a);
	while (stack_length(*a) > 3 && !sorted_stack(*a))
	{
		preparing_a(a, b);
		a_to_b(a, b);
		pb(b, a);
	}
	stack_sort_3(a);
	while (*b)
	{
		preparing_b(b, a);
		b_to_a(b, a);
		pa(a, b);
	}
	take_smallest_up(a, find_smallest(a));
}
