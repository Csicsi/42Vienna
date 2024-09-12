/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:14:48 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:50:22 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
	return ;
}

t_node	*create_node(int value, int rank, t_data *data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		free_split(data->split);
		free_stack(data->a);
		free_stack(data->b);
		handle_error(data->a, data->b);
		exit(1);
	}
	new->value = value;
	new->rank = rank;
	new->target = -1;
	new->cost = -1;
	return (new);
}

void	push_a(int value, int rank, t_data *data)
{
	t_node	*new;
	t_node	*tail;

	new = create_node(value, rank, data);
	if (!new)
		return ;
	if (data->a->head == NULL)
	{
		new->next = new;
		new->prev = new;
		data->a->head = new;
	}
	else
	{
		tail = data->a->head->prev;
		new->next = data->a->head;
		new->prev = tail;
		data->a->head->prev = new;
		tail->next = new;
		data->a->head = new;
	}
	data->a->size++;
}

void	delete(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL || stack->size == 0)
		return ;
	temp = stack->head;
	if (stack->size == 1)
	{
		stack->head = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		stack->head = temp->next;
	}
	free(temp);
	stack->size--;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	i = 0;
	if (stack == NULL || stack->size == 0)
		return ;
	current = stack->head;
	while (i < stack->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	stack->head = NULL;
	stack->size = 0;
}
