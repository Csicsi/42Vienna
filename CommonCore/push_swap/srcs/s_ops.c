/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:44:37 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/01 18:27:22 by dcsicsak         ###   ########.fr       */
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

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
