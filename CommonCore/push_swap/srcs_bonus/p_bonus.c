/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:55:04 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 12:16:14 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(int value, int rank, t_data *data)
{
	t_node	*new;
	t_node	*tail;

	new = create_node(value, rank, data);
	if (!new)
		return ;
	if (data->b->head == NULL)
	{
		new->next = new;
		new->prev = new;
		data->b->head = new;
	}
	else
	{
		tail = data->b->head->prev;
		new->next = data->b->head;
		new->prev = tail;
		data->b->head->prev = new;
		tail->next = new;
		data->b->head = new;
	}
	data->b->size++;
}

void	pa_bonus(t_stack *a, t_stack *b)
{
	t_data	data;

	data.a = a;
	data.b = b;
	data.split = NULL;
	if (b->size > 0)
	{
		push_a(b->head->value, b->head->rank, &data);
		delete(b);
	}
}

void	pb_bonus(t_stack *a, t_stack *b)
{
	t_data	data;

	data.a = a;
	data.b = b;
	data.split = NULL;
	if (a->size > 0)
	{
		push_b(a->head->value, a->head->rank, &data);
		delete(a);
	}
}
