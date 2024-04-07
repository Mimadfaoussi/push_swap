/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:41:10 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/07 19:08:15 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **dst, t_node **src)
{
	t_node	*mid;

	if (!*src)
		return ;
	mid = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	mid->next = *dst;
	if (*dst)
		(*dst)->prev = mid;
	*dst = mid;
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	printf("pb\n");
}

