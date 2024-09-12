/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:32:46 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/02 07:59:48 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_up(t_move_data *data)
{
	while (data->a_index > 0 && data->min_index > 0)
	{
		rr(data->a, data->b);
		data->a_index--;
		data->min_index--;
	}
	while (data->a_index > 0)
	{
		ra(data->a);
		data->a_index--;
	}
	while (data->min_index > 0)
	{
		rb(data->b);
		data->min_index--;
	}
}

static void	rotate_both_down(t_move_data *data)
{
	while (data->a_index < data->a->size && data->min_index < data->b->size)
	{
		rrr(data->a, data->b);
		data->a_index++;
		data->min_index++;
	}
	while (data->a_index < data->a->size)
	{
		rra(data->a);
		data->a_index++;
	}
	while (data->min_index < data->b->size)
	{
		rrb(data->b);
		data->min_index++;
	}
}

static void	rotate_alternate(t_move_data *data)
{
	while (data->a_cost > 0)
	{
		if (data->a_index <= data->a->size / 2)
			ra(data->a);
		else
			rra(data->a);
		data->a_cost--;
	}
	while (data->b_cost > 0)
	{
		if (data->min_index <= data->b->size / 2)
			rb(data->b);
		else
			rrb(data->b);
		data->b_cost--;
	}
}

void	execute_least_cost_move(t_stack *a, t_stack *b, int min_index)
{
	t_node		*b_node;
	int			i;
	t_move_data	data;

	data.a = a;
	data.b = b;
	data.min_index = min_index;
	b_node = b->head;
	i = 0;
	while (i < min_index)
	{
		b_node = b_node->next;
		i++;
	}
	data.a_index = find_index(a, b_node->target);
	data.a_cost = cost_to_top(data.a_index, a->size);
	data.b_cost = cost_to_top(min_index, b->size);
	if (data.a_index <= a->size / 2 && min_index <= b->size / 2)
		rotate_both_up(&data);
	else if (data.a_index > a->size / 2 && min_index > b->size / 2)
		rotate_both_down(&data);
	else
		rotate_alternate(&data);
	pa(a, b);
}
