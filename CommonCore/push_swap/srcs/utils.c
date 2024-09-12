/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:34:09 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:47:07 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

int	has_duplicates(t_stack *stack)
{
	t_node	*outer;
	t_node	*inner;

	if (stack->size < 2)
		return (0);
	outer = stack->head;
	while (outer->next != stack->head)
	{
		inner = outer->next;
		while (inner != stack->head)
		{
			if (outer->value == inner->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
