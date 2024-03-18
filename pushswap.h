/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:55:48 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/18 01:59:26 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node{
	int					value;
	int					current_position;
	int					ordered_position;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_node;

/** list manipulation */
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int value);
t_node	*ft_lstlast(t_node *lst);
void	print_stack(t_node **a);
void	stack_init(t_node **a, char **argv);

char	**ft_split(char const *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);

#endif