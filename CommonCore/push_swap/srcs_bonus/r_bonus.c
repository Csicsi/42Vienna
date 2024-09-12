/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:54:11 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/03 10:56:12 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	if (stack == NULL || stack->size == 0)
		return ;
	stack->head = stack->head->next;
}

void	ra_bonus(t_stack *a)
{
	rotate(a);
}

void	rb_bonus(t_stack *b)
{
	rotate(b);
}

void	rr_bonus(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
