/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:36:31 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/17 13:39:17 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	top;
	int	bottom;
	int	quot;
	int	rem;

	top = 10;
	bottom = 3;
	ft_div_mod(top, bottom, &quot, &rem);
	printf("%d%d", quot, rem);
	return (0);
}*/
