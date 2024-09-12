/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:04:41 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/04/17 10:31:55 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_di(int nbr)
{
	int				i;
	int				rev_digits[100];
	unsigned int	nbu;
	int				digits;

	digits = 0;
	if (nbr == 0)
		return (ft_putchar_fd('0', 1), 1);
	nbu = nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbu = -nbr;
		digits = 1;
	}
	i = 0;
	while (nbu > 0)
	{
		rev_digits[i++] = nbu % 10;
		nbu /= 10;
	}
	digits += i;
	while (i > 0)
		ft_putchar_fd(rev_digits[--i] + '0', 1);
	return (digits);
}
