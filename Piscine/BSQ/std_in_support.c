/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_in_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:23:06 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/06 19:43:31 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

char	*ft_realloc(char *buffer, size_t old_s, size_t new_s, t_mem *track)
{
	char	*new_buffer;
	size_t	min_size;

	if (new_s == 0)
	{
		return (NULL);
	}
	else
	{
		new_buffer = (char *)ft_malloc(new_s, track);
		if (new_buffer == NULL)
		{
			return (NULL);
		}
		if (buffer != NULL)
		{
			if (old_s < new_s)
				min_size = old_s;
			else
				min_size = new_s;
			ft_memcpy(new_buffer, buffer, min_size);
		}
		return (new_buffer);
	}
}

const char	*find_newline(const char *buffer)
{
	while (*buffer != '\0' && *buffer != '\n')
	{
		buffer++;
	}
	if (*buffer == '\n')
	{
		buffer++;
	}
	return (buffer);
}
