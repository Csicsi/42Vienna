/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:36:07 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/03 12:54:50 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*res;
	int	*num;

	num = malloc(length * sizeof(int));
	if (num == NULL)
		return (NULL);
	res = malloc(length * sizeof(int));
	if (res == NULL)
		return (NULL);
	index = 0;
	while (index < length)
	{
		res[index] = (*f)(tab[index]);
		index++;
	}
	return (res);
}
