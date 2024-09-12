/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:41:18 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/02 08:00:49 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	if (a->head->rank > a->head->next->rank
		&& a->head->rank > a->head->prev->rank)
		ra(a);
	else if (a->head->next->rank > a->head->rank
		&& a->head->next->rank > a->head->prev->rank)
		rra(a);
	if (a->head->rank > a->head->next->rank)
		sa(a);
}

static void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*min_node;

	min_node = find_minimum_node(a);
	rotate_to_minimum(a, min_node);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*min_node;

	min_node = find_minimum_node(a);
	rotate_to_minimum(a, min_node);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}
