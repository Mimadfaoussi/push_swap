/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 15:26:12 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_node **a, char **argv, bool flag)
{
	t_node	*node;
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (syntax_checker(argv[i]) == 1)
		{
			ft_putstr("syntax checker error \n");
			free_error(a, argv, flag);
		}
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN || check_repetition(a, nb) == 1)
			free_error(a, argv, flag);
		node = ft_lstnew(nb);
		ft_lstadd_back(a, node);
		i++;
	}
	if (flag)
		free_all_str(argv);
}


bool	sorted_stack(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	stack_length(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
