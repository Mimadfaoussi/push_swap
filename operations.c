/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/18 06:38:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_init(t_node **a, char **argv, bool flag)
{
	t_node	*node;
	int		i;
	int		nb;

	i = 0;
	while (argv[i])
	{
		if (syntax_checker(argv[i]) == 1)
			free_error(a, argv, flag);
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_error(a, argv, flag);
		//check for repetition
		node = ft_lstnew(i);
		ft_lstadd_back(a, node);
		i++;
	}
	if (flag)
		free_all(argv);
}

void	print_stack(t_node **a)
{
	t_node	*index;

	index = *a;
	while (index)
	{
		printf("%d\n",index->value);
		index = index->next;
	}
}
