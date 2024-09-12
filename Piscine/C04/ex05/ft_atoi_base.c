/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:11:08 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/29 11:52:07 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '\0')
	{
		return (0);
	}
	if (str[0] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

void	ft_atoi_base(char *str, char *base)
{
	int	number;
	int	len;

	len = 0;
	number = ft_atoi(str);
	while (base[len])
	{
		len++;
	}
	if (!check_base(base))
		return ;
	base_rec(number, base, len);
}
