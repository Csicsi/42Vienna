/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:53 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/22 17:45:16 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <limits.h>*/

int	ft_sqrt_rec(int nb, long long root)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	if (root * root == nb)
		return (root);
	if (root * root > nb)
		return (0);
	return (ft_sqrt_rec(nb, root + 1));
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_rec(nb, 2));
}

/*int	main(void)
{
	printf("%d", ft_sqrt(INT_MAX));
	return (0);
}*/
