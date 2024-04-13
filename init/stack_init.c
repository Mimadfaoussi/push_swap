/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 15:49:34 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
* stack_init-goes through each element in argv , check it valid and push
* @a: the stack we're pushing into
* @argv: the arguments we're going through
* @flag: to check if we had 2 or more parameteres to free the memory after
**/

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

