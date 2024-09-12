/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalajqi <lalajqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:44:43 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/03 22:38:14 by lalajqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen2(char *str)
{
	int	temp;

	temp = 0;
	while (*str)
	{
		temp++;
		str++;
	}
	return (temp);
}

char	*ft_strcpy2(char *dest, char *src)
{
	int	size;
	int	index;

	size = 0;
	index = 0;
	while (*src != '\0')
	{
		size++;
		src++;
	}
	src = src - size;
	while (index < size && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen2(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy2(dest, src));
}
