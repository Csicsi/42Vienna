/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:30:36 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/16 14:27:31 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*temp;

	temp = (char *)s;
	index = 0;
	while (index < n)
	{
		temp[index++] = 0;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
