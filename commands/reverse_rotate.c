/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:41:10 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/08 16:52:31 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*index;

	if (!*head || stack_length(*head) == 1)
		return ;
	last = ft_lstlast(*head);
	index = *head;
	last->next = *head;
	(*head)->prev = last;
	(last->prev)->next = NULL;
	last->prev = NULL;
	*head = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
