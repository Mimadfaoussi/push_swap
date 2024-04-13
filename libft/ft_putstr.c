/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:03:34 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 16:05:07 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
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