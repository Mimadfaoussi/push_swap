/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:39:18 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 16:58:27 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	syntax_checker(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	free_error(t_node **a, char **argv, bool flag)
{
	ft_lstclear(a);
	if (flag == true)
		free_all_str(argv);
	exit(0);
}

int	check_repetition(t_node **a, int nb)
{
	t_node	*index;

	index = *a;
	while (index)
	{
		if (index->value == nb)
		{
			return (1);
		}
		index = index->next;
	}
	return (0);
}

void	free_stack(t_node **a)
{
	ft_lstclear(a);
}
