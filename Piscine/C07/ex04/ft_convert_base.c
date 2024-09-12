/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:11:08 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/29 21:55:43 by dcsicsak         ###   ########.fr       */
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

int	in_base(char c, char *base_from)
{
	int	index;

	index = 0;
	while (base_from[index])
	{
		if (c == base_from[index])
		{
			return (1);
		}
	}
	return (0);
}

char	*ft_atoi(char *str, char *base_from)
{
	int	i;
	int	j;
	char result[100];

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	j = 0;
	while (in_base(str[i], base_from))
	{
		result[j] = str[i];
		i++;
		j++;
	}
	return (&result);
}

int	is_negative(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	return (sign + 1);
}

int	base_to_int(char *number, char *base_from, char *str)
{
	int	base;
	int	result;
	int	digit;

	base = 0;
	result = 0;
	while (base_from[base])
	{
		base++;
	}
	while (*number)
	{
		digit = 0;
		while (base_from[digit] != *number)
		{
			digit++;
		}
		result = result * base + digit;
		number++;
	}
	if (is_negative(str))
	{
		result = -result;
	}
	return (result);
}

void	ft_convert_base(char *str, char *base_from, char *base_to)
{
	int		number;
	int		len;
	char	*nbr;

	len = 0;
	if (!check_base(base_from))
		return ;
	nbr = ft_atoi(str, base_from);
	number = base_to_int(nbr, base_from, str);
	while (base_to[len])
	{
		len++;
	}
	if (!check_base(base_to))
		return ;
	base_rec(number, base_to, len);
}
