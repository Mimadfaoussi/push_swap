/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:55:48 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/06 18:47:14 by mfaoussi         ###   ########.fr       */
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

char	**ft_split(char const *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);
void	free_all_str(char **res);
int		ft_atoi(const char *str);

/** Errors checking */
int		syntax_checker(char *nbr);
void	ft_lstclear(t_node **lst);
void	free_error(t_node **a, char **argv, bool flag);
int		check_repetition(t_node **a, int nb);

#endif