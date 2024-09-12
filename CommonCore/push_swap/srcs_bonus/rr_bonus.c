/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:53:29 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/03 10:56:30 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	if (stack == NULL || stack->size == 0)
		return ;
	stack->head = stack->head->prev;
}

void	rra_bonus(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb_bonus(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr_bonus(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
