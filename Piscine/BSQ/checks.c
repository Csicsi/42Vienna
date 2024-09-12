/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:56:36 by icseri            #+#    #+#             */
/*   Updated: 2024/03/06 21:51:08 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	row_count_check(char *file_name, t_mem *track)
{
	int		j;
	int		i;
	int		len;
	char	*str;

	str = get_file_content(file_name, track);
	i = 0;
	j = 0;
	len = get_column_count(file_name);
	if (str == NULL)
		return (0);
	while (str[j] != 0)
	{
		if (str[j] == '\n')
		{
			i++;
			if ((j + 1) % len != 0)
				return (0);
		}
		j++;
	}
	if (i + 1 != get_row_count(get_first_line(file_name, track))
		|| (j + 1) % len != 0 || ft_strlen(str) == 0)
		return (0);
	return (1);
}

int	symbol_check(char *symbols)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(symbols) != 3)
		return (0);
	while (symbols[i])
	{
		j = i + 1;
		while (symbols[j])
		{
			if (symbols[i] == symbols[j]
				|| (symbols[i] < 32 || symbols[i] == 127))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	content_check(char *symbols, char *content)
{
	int		i;

	i = 0;
	if (content[0] == '\0')
		return (0);
	while (content[i])
	{
		if (content[i] != symbols[0]
			&& content[i] != symbols[1] && content[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	map_check(char	*file_name, t_mem *track)
{
	char	*fr_ln;
	char	*content;

	fr_ln = get_first_line(file_name, track);
	content = get_file_content(file_name, track);
	if (get_file_size(file_name) <= 0)
		return (ft_puterror("map error\n"), 0);
	else if (row_count_check(file_name, track) == 0)
		return (ft_puterror("map error\n"), 0);
	else if (symbol_check(get_symbols(fr_ln, track)) == 0)
		return (ft_puterror("map error\n"), 0);
	else if (content_check(get_symbols(fr_ln, track), content) == 0)
		return (ft_puterror("map error\n"), 0);
	return (1);
}

int	stdin_chk(char *fr_ln, char *content, t_crd row_col, t_mem *track)
{
	if (row_col.y == 0)
		return (ft_puterror("map error\n"), 0);
	else if (get_row_count(fr_ln) != row_col.x)
		return (ft_puterror("map error\n"), 0);
	else if (symbol_check(get_symbols(fr_ln, track)) == 0)
		return (ft_puterror("map error\n"), 0);
	else if (content_check(get_symbols(fr_ln, track), content) == 0)
		return (ft_puterror("map error\n"), 0);
	return (1);
}
