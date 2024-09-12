/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:29:07 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/26 13:32:13 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	index;

	if (min >= max)
		return (NULL);
	range = malloc((max - min) * sizeof(int));
	if (range == NULL)
		return (NULL);
	index = 0;
	while (min < max)
	{
		range[index] = min;
		min++;
		index++;
	}
	return (range);
}
