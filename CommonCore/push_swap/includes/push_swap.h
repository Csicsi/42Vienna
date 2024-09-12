/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:20:50 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:54:12 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				rank;
	int				target;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

typedef struct s_cost
{
	int	a_index;
	int	a_size;
	int	b_index;
	int	b_size;
}	t_cost;

typedef struct s_move_data
{
	t_stack	*a;
	t_stack	*b;
	int		a_index;
	int		min_index;
	int		a_cost;
	int		b_cost;
}	t_move_data;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**split;
}	t_data;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa_bonus(t_stack *a);
void	sb_bonus(t_stack *b);
void	ss_bonus(t_stack *a, t_stack *b);
void	pa_bonus(t_stack *a, t_stack *b);
void	pb_bonus(t_stack *a, t_stack *b);
void	ra_bonus(t_stack *a);
void	rb_bonus(t_stack *b);
void	rr_bonus(t_stack *a, t_stack *b);
void	rra_bonus(t_stack *a);
void	rrb_bonus(t_stack *b);
void	rrr_bonus(t_stack *a, t_stack *b);
void	push_a(int value, int rank, t_data *data);
void	delete(t_stack *stack);
void	free_stack(t_stack *stack);
void	init_stack(t_stack *stack);
void	sort(t_stack *a, t_stack *b);
int		calculate_cost(t_stack *a, t_stack *b);
void	perform_cheapest_move(t_stack *a, t_stack *b, int min_cost_index);
int		find_index(t_stack *stack, int rank);
int		cost_to_top(int index, int size);
void	execute_least_cost_move(t_stack *a, t_stack *b, int min_index);
void	rank_numbers(t_stack *a);
void	handle_error(t_stack *a, t_stack *b);
void	free_split(char **split);
int		initialize(int argc, char **argv, t_stack **a, t_stack **b);
int		has_duplicates(t_stack *stack);
t_node	*find_minimum_node(t_stack *a);
void	rotate_to_minimum(t_stack *a, t_node *min_node);
void	simple_sort(t_stack *a, t_stack *b);
int		calculate_cost_rr(t_cost params);
int		calculate_cost_rrr(t_cost params);
int		calculate_cost_alternating(t_cost params, int a_cost, int b_cost);
t_node	*create_node(int value, int rank, t_data *data);

#endif
