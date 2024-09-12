/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:27:46 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/22 17:44:42 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <limits.h>*/

int	ft_iterative_power(int nb, int power)
{
	int	number;

	number = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power - 1)
	{
		nb *= number;
		power--;
	}
	return (nb);
}

/*int	main(void)
{
	int	nb;
	int	power;

	nb = -2;
	power = 3;
	printf("%d", ft_iterative_power(nb, power));
	return (0);
}*/
