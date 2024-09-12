/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpanic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:14:28 by vpanic            #+#    #+#             */
/*   Updated: 2024/03/02 19:14:33 by vpanic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_itoa(int n)
{
	int		num;
	int		temp;
	char	*result;
	int		i;

	num = 1;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		if (temp != 0)
			num++;
	}
	result = malloc(num + 1);
	if (!result)
		return (NULL);
	i = num - 1;
	result[num] = '\0';
	while (i >= 0)
	{
		result[i--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
