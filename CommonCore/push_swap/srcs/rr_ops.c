/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:23:56 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/01 18:27:22 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	if (stack == NULL || stack->size == 0)
		return ;
	stack->head = stack->head->prev;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
