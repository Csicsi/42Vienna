/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:43:54 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/01 18:44:14 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_rr(t_cost params)
{
	if (params.a_index > params.b_index)
		return (params.a_index);
	else
		return (params.b_index);
}

int	calculate_cost_rrr(t_cost params)
{
	int	cost_a;
	int	cost_b;

	cost_a = params.a_size - params.a_index;
	cost_b = params.b_size - params.b_index;
	if (cost_a > cost_b)
		return (cost_a);
	else
		return (cost_b);
}

int	calculate_cost_alternating(t_cost params, int a_cost, int b_cost)
{
	int	cost_ra_rrb;
	int	cost_rra_rb;

	cost_ra_rrb = a_cost + (params.b_size - params.b_index);
	cost_rra_rb = (params.a_size - params.a_index) + b_cost;
	if (cost_ra_rrb < cost_rra_rb)
		return (cost_ra_rrb);
	else
		return (cost_rra_rb);
}
