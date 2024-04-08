/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:52:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/06 18:48:05 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *find_biggest(t_node **a)
{
    t_node  *biggest;
    t_node  *index;

    if (!*a)
        return (NULL);
    biggest = *a;
    index = *a;
    while (index)
    {
        if (index->value > biggest->value)
            biggest = index;
        index = index->next;
    }
    return (biggest);
}

// void    stack_sort_3(t_node **a)
// {

// }
