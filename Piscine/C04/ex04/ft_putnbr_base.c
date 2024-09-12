/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:11:08 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/29 11:24:46 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	check_base(char *base)
{
	int	index;
	int	duplicate[256];

	index = 0;
	while (index < 256)
	{
		duplicate[index] = 0;
		index++;
	}
	index = 0;
	while (base[index])
	{
		if (duplicate[(unsigned char)base[index]])
			return (0);
		if (base[index] == '+' || base[index] == '-')
			return (0);
		duplicate[(unsigned char)base[index]] = 1;
		index++;
	}
	if (index <= 1)
		return (0);
	return (1);
}

void	base_rec(int nbr, char *base, int len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= len)
	{
		base_rec(nbr / len, base, len);
		ft_putchar(base[nbr % len]);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (!check_base(base))
		return ;
	base_rec(nbr, base, len);
}
