/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:02:21 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/12 15:21:03 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


void	take_smallest_up(t_node **a, t_node *smallest)
{
	while (on_top(a, smallest) == 0)
	{
		if (smallest->above_median == true)
			ra(a);
		else
			rra(a);
	}
}
