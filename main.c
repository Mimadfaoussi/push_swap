/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:33:22 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/18 06:14:30 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	stack_init(&a, argv + 1, argc == 2);
	print_stack(&a);
	return (0);
}
