/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:18:18 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 15:44:45 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*index;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		index = ft_lstlast(*lst);
		index->next = new;
		new->prev = index;
	}
}

t_node	*ft_lstnew(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*index;

	index = lst;
	if (lst == NULL)
		return (NULL);
	while (index->next != NULL)
		index = index->next;
	return (index);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*index;

	while (*lst != NULL)
	{
		index = *lst;
		*lst = (*lst)->next;
		index->next = NULL;
		free(index);
	}
	lst = NULL;
}
