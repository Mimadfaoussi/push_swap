/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:33:22 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 15:28:24 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printlst(char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		printf("%s\n", argv[i]);
// 		i++;
// 	}
// }

// void	print_stack(t_node **a)
// {
// 	t_node	*index;

// 	if (!*a)
// 		return ;
// 	index = *a;
// 	while (index)
// 	{
// 		printf("%d\n",index->value);
// 		// printf("cheapest = %d\n", index->cheapest);
// 		index = index->next;
// 	}
// }

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
		stack_init(&a, argv, argc == 2);
	if (!sorted_stack(a))
	{
		if (stack_length(a) == 2)
			sa(&a);
		else if (stack_length(a) == 3)
			stack_sort_3(&a);
		else
			stack_sort(&a, &b);
	}
	// print_stack(&a);
	return (0);
}
