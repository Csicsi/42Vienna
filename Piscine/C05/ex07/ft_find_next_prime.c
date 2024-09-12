/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:22:43 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/28 14:57:07 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <limits.h>

int	ft_is_prime(int nb)
{
	long	index;
	long	prime;

	index = 2;
	prime = 0;
	if (nb < 2)
	{
		return (0);
	}
	if (nb == 2)
	{
		return (1);
	}
	while (index <= nb / 2)
	{
		if (nb % index == 0)
		{
			prime++;
		}
		index++;
	}
	if (prime == 0)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	long	number;

	number = nb;
	if (ft_is_prime(number))
	{
		return (number);
	}
	while (number <= INT_MAX)
	{
		if (ft_is_prime(number))
		{
			return (number);
		}
		number++;
	}
	return (0);
}

/*int	main(void)
{
	int	num;

	printf("Enter a number: ");
	scanf("%d", &num);
	printf("%d", ft_find_next_prime(num));
}*/
