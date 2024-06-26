/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:55:48 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/13 18:31:13 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_node;

/** list manipulation */
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int value);
t_node	*ft_lstlast(t_node *lst);
void	print_stack(t_node **a);
void	stack_init(t_node **a, char **argv, bool flag);
t_node	*find_biggest(t_node **a);

char	**ft_split(char const *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);
void	free_all_str(char **res);
void	free_stack(t_node **a);
long	ft_atoi(const char *str);

/** Errors checking */
int		syntax_checker(char *nbr);
void	ft_lstclear(t_node **lst);
void	free_error(t_node **a, char **argv, bool flag);
int		check_repetition(t_node **a, int nb);

/** stack functions */
bool	sorted_stack(t_node *a);
int		stack_length(t_node *stack);
void	stack_sort_3(t_node **a);
void	stack_sort(t_node **a, t_node **b);

/** stack commands */
void	swap(t_node	**head);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	push(t_node **dst, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	rotate(t_node **head);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **head);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/** stack init */
void	preparing_a(t_node **a, t_node **b);
void	index_position(t_node **stack);
void	a_targets(t_node **a, t_node **b);
void	set_cost_a(t_node **a, t_node **b);
void	set_cheapest(t_node **a);
void	init_cheapest_false(t_node **a);
t_node	*find_cheapest(t_node **a);
void	a_to_b(t_node **a, t_node **b);
void	take_cheapest_up(t_node **a, t_node **b, t_node *cheapest);
void	take_cheapest_up_b(t_node **a, t_node **b, t_node *cheapest);
int		on_top(t_node **stack, t_node *elm);
int		same_direction(t_node *elm);
void	set_cheapest(t_node **a);

/*** stack b to a */
void	preparing_b(t_node **b, t_node **a);
void	b_targets(t_node **b, t_node **a);
void	b_to_a(t_node **a, t_node **b);
t_node	*find_smallest(t_node **stack);
void	set_cost_b(t_node **b, t_node **a);
void	take_smallest_up(t_node **a, t_node *smallest);
void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif