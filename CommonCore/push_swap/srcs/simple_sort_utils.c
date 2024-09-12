/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:42:00 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/01 18:42:22 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_minimum_node(t_stack *a)
{
	t_node	*min_node;
	t_node	*a_node;

	min_node = a->head;
	a_node = a->head->next;
	while (a_node != a->head)
	{
		if (a_node->rank < min_node->rank)
			min_node = a_node;
		a_node = a_node->next;
	}
	return (min_node);
}

void	rotate_to_minimum(t_stack *a, t_node *min_node)
{
	t_node	*a_node;
	int		index;

	a_node = a->head;
	index = 0;
	while (a_node != min_node)
	{
		a_node = a_node->next;
		index++;
	}
	if (index < a->size / 2)
	{
		while (a->head != min_node)
			ra(a);
	}
	else
	{
		while (a->head != min_node)
			rra(a);
	}
}
