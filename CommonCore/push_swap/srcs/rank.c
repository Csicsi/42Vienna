/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:35:34 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:46:49 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_numbers(t_stack *a)
{
	t_node	*cur;
	t_node	*comp;
	int		rank;

	rank = 1;
	if (a->size == 0)
		return ;
	cur = a->head;
	while (rank > 0)
	{
		rank = 1;
		comp = a->head;
		while (1)
		{
			if (comp->value < cur->value)
				rank++;
			comp = comp->next;
			if (comp == a->head)
				break ;
		}
		cur->rank = rank;
		cur = cur->next;
		if (cur == a->head)
			rank = -1;
	}
}
