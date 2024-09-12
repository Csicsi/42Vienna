/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:22:29 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/06 16:33:17 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_alloc(t_mem *track)
{
	track->allocated_memory = (void **)malloc(100 * sizeof(void *));
	if (track->allocated_memory == NULL)
	{
		exit(1);
	}
	track->allocated_capacity = 100;
	track->allocated_count = 0;
}

void	*ft_malloc(size_t size, t_mem *track)
{
	size_t	new_capacity;
	void	**new_memory;
	size_t	index;
	void	*ptr;

	index = 0;
	if (track->allocated_count == track->allocated_capacity)
	{
		new_capacity = track->allocated_capacity * 2;
		new_memory = (void **)malloc(new_capacity * sizeof(void *));
		if (new_memory == NULL)
			exit(1);
		while (index < track->allocated_count)
		{
			new_memory[index] = track->allocated_memory[index];
			index++;
		}
		free(track->allocated_memory);
		track->allocated_memory = new_memory;
		track->allocated_capacity = new_capacity;
	}
	ptr = malloc(size);
	if (ptr != NULL)
		track->allocated_memory[track->allocated_count++] = ptr;
	return (ptr);
}

void	free_all(t_mem *track)
{
	size_t	index;

	index = 0;
	while (index < track->allocated_count)
	{
		free(track->allocated_memory[index]);
		index++;
	}
	free(track->allocated_memory);
	track->allocated_memory = NULL;
	track->allocated_count = 0;
	track->allocated_capacity = 0;
}
