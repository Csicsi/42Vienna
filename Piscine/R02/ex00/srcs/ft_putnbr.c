/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:44:39 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/22 21:49:11 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	int				i;
	int				rev_digits[100];
	unsigned int	nbu;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	nbu = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbu = -nb;
	}
	i = 0;
	while (nbu > 0)
	{
		rev_digits[i] = nbu % 10;
		nbu /= 10;
		i++;
	}
	while (i > 0)
		ft_putchar(rev_digits[--i] + '0');
}
