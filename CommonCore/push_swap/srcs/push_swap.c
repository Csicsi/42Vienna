/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:44:36 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/01 18:35:49 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!initialize(argc, argv, &a, &b))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	rank_numbers(a);
	if (has_duplicates(a))
	{
		free_stack(a);
		free_stack(b);
		handle_error(a, b);
	}
	sort(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (0);
}
