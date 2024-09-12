/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:26:52 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:31:16 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_stack *a, t_stack *b)
{
	t_node	*b_node;
	t_node	*a_node;
	int		i;
	int		j;
	int		min;

	i = 0;
	b_node = b->head;
	while (i < b->size)
	{
		min = -1;
		j = 0;
		a_node = a->head;
		while (j < a->size)
		{
			if (a_node->rank > b_node->rank
				&& (min == -1 || a_node->rank < min))
				min = a_node->rank;
			a_node = a_node->next;
			j++;
		}
		b_node->target = min;
		b_node = b_node->next;
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size < 2)
		return (1);
	current = stack->head;
	while (current->next != stack->head)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	pre_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	while (a->size > 5 && !is_sorted(a))
	{
		if (a->head->rank == size
			|| a->head->rank == size - 1 || a->head->rank == size - 2
			|| a->head->rank == size - 3 || a->head->rank == size - 4)
			ra(a);
		else
		{
			pb(a, b);
			if (b->head->rank < size / 3)
				rb(b);
		}
	}
	simple_sort(a, b);
}

static void	final_sort(t_stack *a, t_stack *b)
{
	int		min_index;
	int		i;
	t_node	*current;

	while (b->size > 0)
	{
		find_target(a, b);
		min_index = calculate_cost(a, b);
		execute_least_cost_move(a, b, min_index);
	}
	current = a->head;
	i = 0;
	while (current->rank != 1)
	{
		current = current->next;
		i++;
	}
	min_index = a->size / 2;
	while (a->head->rank != 1)
	{
		if (i < min_index)
			ra(a);
		else
			rra(a);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	pre_sort(a, b);
	final_sort(a, b);
}
