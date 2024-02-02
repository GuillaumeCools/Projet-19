/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:20:09 by guillaumeco       #+#    #+#             */
/*   Updated: 2024/01/25 13:34:04 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../printf/includes/ft_printf.h"
# include "../printf/includes/libft.h"

typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

void			free_errors(t_stack_node **a);
void			free_stack(t_stack_node **stack);
int				errors_duplicate(t_stack_node *a, int n);
int				error_syntax(char *str_n);

void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);

void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

bool			stack_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);


#endif

