/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:17:09 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/26 06:18:07 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	numlen(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_sttoa(size_t n)
{
	int		len;
	char	*str;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

size_t	ft_atost(const char *nptr)
{
	size_t	i;
	size_t	number;
	size_t	previous;

	i = 0;
	number = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		previous = number;
		number = number * 10 + (nptr[i] - '0');
		if (number < previous)
			return (SIZE_MAX);
		i++;
	}
	return (number);
}

size_t	ft_strlen(const char *s)
{
	size_t	temp;

	temp = 0;
	while (*s != '\0')
	{
		temp++;
		s++;
	}
	return (temp);
}
