/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:31:25 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/04 14:50:54 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	valid_plcmnt(t_map map, t_crd crd)
{
	int	index1;
	int	index2;

	if (crd.x + crd.size > map.row || crd.y + crd.size > map.column)
	{
		return (false);
	}
	index1 = 0;
	while (index1 < crd.size)
	{
		index2 = 0;
		while (index2 < crd.size)
		{
			if (map.map[index1 + crd.x][index2 + crd.y] == crd.obs)
			{
				return (false);
			}
			index2++;
		}
		index1++;
	}
	return (true);
}

void	solve(t_map map, t_crd *top_lft, int *max, char *symbols)
{
	int		x;
	int		y;
	int		current_size;

	*max = 0;
	x = 0;
	while (x < map.row)
	{
		y = 0;
		while (y < map.column)
		{
			current_size = *max + 1;
			while (x + current_size <= map.row
				&& y + current_size <= map.column
				&& valid_plcmnt(map, (t_crd){x, y, current_size, symbols[1]}))
			{
				*max = current_size;
				top_lft->x = x;
				top_lft->y = y;
				++current_size;
			}
			y++;
		}
		x++;
	}
}

void	drawing_square(t_map map, t_crd top_lft, int max, char full)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (index1 < max)
	{
		index2 = 0;
		while (index2 < max)
		{
			map.map[index1 + top_lft.x][index2 + top_lft.y] = full;
			index2++;
		}
		index1++;
	}
}

void	prnt_sq(char *content, t_crd row_col, char *symbols, t_mem *track)
{
	int		i;
	int		j;
	int		max_size;
	t_map	map;
	t_crd	top_left;

	map.map = input_parsing(content, row_col.x, row_col.y, track);
	map.row = row_col.x;
	map.column = row_col.y;
	top_left.x = 0;
	top_left.y = 0;
	top_left.size = 0;
	top_left.obs = 0;
	max_size = 0;
	solve(map, &top_left, &max_size, symbols);
	drawing_square(map, top_left, max_size, symbols[2]);
	i = 0;
	while (i < map.row)
	{
		j = 0;
		while (j < map.column)
			ft_putchar(map.map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
