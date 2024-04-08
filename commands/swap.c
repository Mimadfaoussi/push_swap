/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:54:47 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/08 16:43:43 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node	**head)
{
	t_node	*p1;

	if (!*head || !((*head)->next))
		return ;
	p1 = *head;
	*head = (*head)->next;
	p1->next = (*head)->next;
	p1->prev = *head;
	if ((*head)->next)
		(*head)->next->prev = p1;
	(*head)->next = p1;
	(*head)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
