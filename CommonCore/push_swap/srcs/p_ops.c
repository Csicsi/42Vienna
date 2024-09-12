/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:42 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 12:18:31 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_data	data;

	data.a = a;
	data.b = b;
	data.split = NULL;
	if (b->size > 0)
	{
		push_a(b->head->value, b->head->rank, &data);
		delete(b);
		ft_printf("pa\n");
	}
}

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

void	pb(t_stack *a, t_stack *b)
{
	t_data	data;

	data.a = a;
	data.b = b;
	data.split = NULL;
	if (a->size > 0)
	{
		push_b(a->head->value, a->head->rank, &data);
		delete(a);
		ft_printf("pb\n");
	}
}
