/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:33:22 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/07 19:10:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlst(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2) && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc > 2)
		stack_init(&a, argv + 1, argc == 2);
	else
 		stack_init(&a, argv , argc == 2);
	if (!sorted_stack(a))
	{
		// printf("stack is not sorted %d\n",stack_length(a));
		if (stack_length(a) == 2) 
			sa(&a);
		// else if (stack_length(a) == 3)
		// 	stack_sort_3(&a);
		// else
		// 	stack_sort(&a, &b);
	}
	pb(&b, &a);
	print_stack(&b);
	pa(&a, &b);
	print_stack(&a);
	// free_stack(&a)
	return (0);
}
