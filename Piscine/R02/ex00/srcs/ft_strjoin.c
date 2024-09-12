/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:21:47 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/29 13:41:22 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_empty(void)
{
	char	*empty;

	empty = malloc(1);
	if (empty == NULL)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		mem_size;
	int		index;
	char	*result;

	index = 0;
	mem_size = 0;
	if (size == 0)
		return (ft_empty());
	while (index < size)
		mem_size += ft_strlen(strs[index++]);
	mem_size += (size - 1) * ft_strlen(sep);
	result = malloc((mem_size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	index = 0;
	while (index < size)
	{
		ft_strcat(result, strs[index]);
		if (index != (size - 1))
			ft_strcat(result, sep);
		index++;
	}
	return (result);
}
