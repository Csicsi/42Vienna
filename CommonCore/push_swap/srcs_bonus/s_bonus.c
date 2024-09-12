/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:52:31 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/03 10:56:45 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp_rank;
	int	temp_val;

	if (stack->size < 2)
		return ;
	temp_rank = stack->head->rank;
	stack->head->rank = stack->head->next->rank;
	stack->head->next->rank = temp_rank;
	temp_val = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp_val;
}

void	sa_bonus(t_stack *a)
{
	swap(a);
}

void	sb_bonus(t_stack *b)
{
	swap(b);
}

void	ss_bonus(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
