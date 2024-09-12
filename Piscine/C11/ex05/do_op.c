/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:10:42 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/07 10:13:51 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_div_zero(void)
{
	int	len;

	len = sizeof("Stop : division by zero");
	write(1, "Stop : division by zero", len);
}

void	ft_mod_zero(void)
{
	int	len;

	len = sizeof("Stop : modulo by zero");
	write(1, "Stop : modulo by zero", len);
}

void	doop(char *operator, int a, int b)
{
	if (ft_strcmp(operator, "+") == 0)
		ft_putnbr(ft_add(a, b));
	else if (ft_strcmp(operator, "-") == 0)
		ft_putnbr(ft_sub(a, b));
	else if (ft_strcmp(operator, "*") == 0)
		ft_putnbr(ft_mul(a, b));
	else if (ft_strcmp(operator, "/") == 0)
	{
		if (b == 0)
			ft_div_zero();
		else
			ft_putnbr(ft_div(a, b));
	}
	else if (ft_strcmp(operator, "%") == 0)
	{
		if (b == 0)
			ft_mod_zero();
		else
			ft_putnbr(ft_mod(a, b));
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		doop(argv[2], a, b);
	}
	return (0);
}
