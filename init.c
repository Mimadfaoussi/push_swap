/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/08 19:44:38 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    preparing_a(t_node **a, t_node **b)
{
    index_position(a);
    index_position(b);

}

void    index_position(t_node **stack)
{
    t_node  *index;
    int     i;
    int     middle;

    if (!*stack)
        return ;
    index = *stack;
    middle = stack_length(*stack) / 2;
    i = 0;
    while (index)
    {
        if (i <= middle)
            index->above_median = true;
        else
            index->above_median = false;
        index->index = i;
        index = index->next;
        i++;
    }
}
