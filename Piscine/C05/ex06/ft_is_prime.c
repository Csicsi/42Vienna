/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:22:43 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/28 14:39:12 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_is_prime(int nb)
{
	int	index;
	int	prime;

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

/*int	main(void)
{
	int	num;

	printf("Enter a number: ");
	scanf("%d", &num);
	if (ft_is_prime(num))
	{
		printf("Prime\n");
	}
	else
	{
		printf("Non prime");
	}
}*/
