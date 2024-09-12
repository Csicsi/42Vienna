/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:39:53 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:30:15 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_top(int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	find_index(t_stack *stack, int rank)
{
	t_node	*node;
	int		index;

	node = stack->head;
	index = 0;
	while (node)
	{
		if (node->rank == rank)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}

static void	process_b_node(t_stack *a, t_stack *b, t_node *b_node, int b_index)
{
	int		a_index;
	int		a_cost;
	int		b_cost;
	t_cost	params;

	a_index = find_index(a, b_node->target);
	if (a_index == -1)
		return ;
	a_cost = cost_to_top(a_index, a->size);
	b_cost = cost_to_top(b_index, b->size);
	params = (t_cost){a_index, a->size, b_index, b->size};
	if (a_index <= a->size / 2 && b_index <= b->size / 2)
		b_node->cost = calculate_cost_rr(params);
	else if (a_index > a->size / 2 && b_index > b->size / 2)
		b_node->cost = calculate_cost_rrr(params);
	else
		b_node->cost = calculate_cost_alternating(params, a_cost, b_cost);
}

int	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*b_node;
	int		b_index;
	int		min_cost;
	int		min_index;

	b_node = b->head;
	b_index = 0;
	min_cost = INT_MAX;
	min_index = -1;
	while (b_index < b->size)
	{
		process_b_node(a, b, b_node, b_index);
		if (b_node->cost < min_cost)
		{
			min_cost = b_node->cost;
			min_index = b_index;
		}
		b_node = b_node->next;
		b_index++;
	}
	return (min_index);
}
