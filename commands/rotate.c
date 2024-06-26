/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:52:52 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 15:23:32 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **head)
{
	t_node	*last;
	t_node	*index;

	if (!*head || stack_length(*head) == 1)
		return ;
	index = *head;
	last = ft_lstlast(*head);
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next = index;
	index->next = NULL;
	index->prev = last;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
