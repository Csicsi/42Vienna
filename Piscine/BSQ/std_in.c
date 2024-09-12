/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:17:07 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/06 19:45:54 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*read_input(t_mem *track)
{
	char	*buffer;
	char	ch;
	size_t	buffer_size;
	ssize_t	n_read;

	buffer = NULL;
	buffer_size = 0;
	while (1)
	{
		n_read = read(STDIN_FILENO, &ch, 1);
		if (n_read <= 0)
			break ;
		buffer = ft_realloc(buffer, buffer_size, buffer_size + 1, track);
		if (buffer == NULL)
			return (NULL);
		buffer[buffer_size] = ch;
		buffer_size++;
	}
	buffer = ft_realloc(buffer, buffer_size, buffer_size + 1, track);
	if (n_read < 0 || buffer == NULL)
		return (NULL);
	buffer[buffer_size] = '\0';
	return (buffer);
}

int	stdin_col_count(char *buffer)
{
	int	count;

	count = 0;
	while (*buffer != '\n' && *buffer != '\0')
	{
		buffer++;
	}
	buffer++;
	while (*buffer != '\n' && *buffer != '\0')
	{
		buffer++;
		count++;
	}
	return (count);
}

int	stdin_row_count(char *buffer)
{
	int	count;

	count = 0;
	while (*buffer != '\0')
	{
		if (*buffer == '\n')
		{
			count++;
		}
		buffer++;
	}
	return (count - 1);
}

char	*stdin_first_line(char *buffer, t_mem *track)
{
	char	*res;
	char	*start;
	int		length;

	length = 0;
	while (buffer[length] != '\n' && buffer[length] != '\0')
	{
		length++;
	}
	res = ft_malloc(length + 1, track);
	if (res == NULL)
	{
		return (NULL);
	}
	start = res;
	while (*buffer != '\n' && *buffer != '\0')
	{
		*res++ = *buffer++;
	}
	*res = '\0';
	return (start);
}

char	*stdin_map(const char *buffer, t_mem *track)
{
	const char	*newline_pos;
	int			length;
	char		*res;
	char		*start;
	const char	*temp;

	length = 0;
	newline_pos = find_newline(buffer);
	if (*newline_pos == '\0')
		return (NULL);
	temp = newline_pos;
	while (*temp != '\0')
	{
		length++;
		temp++;
	}
	res = ft_malloc(length + 1, track);
	if (res == NULL)
		return (NULL);
	start = res;
	while (*newline_pos != '\0')
		*res++ = *newline_pos++;
	*res = '\0';
	return (start);
}
