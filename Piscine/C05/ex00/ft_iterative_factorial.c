/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:17:42 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/22 17:30:40 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <limits.h>*/

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb)
	{
		factorial = factorial * nb;
		nb--;
	}
	return (factorial);
}

/*int	main(void)
{
	int number;

	number = INT_MIN;
	printf("%d", ft_iterative_factorial(number));
	return (0);
}*/
