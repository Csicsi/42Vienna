/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:12:52 by icseri            #+#    #+#             */
/*   Updated: 2024/03/04 13:12:54 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_first_line(char *file_name, t_mem *track)
{
	int		fd;
	char	*fr_ln;

	fr_ln = ft_malloc(get_size(file_name, '\n', 1), track);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ("-1");
	read(fd, fr_ln, get_size(file_name, '\n', 1));
	close(fd);
	return (fr_ln);
}

char	*get_file_content(char *file_name, t_mem *track)
{
	char	*content;
	int		fd;
	ssize_t	bytes_read;
	int		file_size;
	int		start;

	start = get_size(file_name, '\n', 1);
	file_size = get_file_size(file_name);
	content = ft_malloc(sizeof(char) * (file_size + 1), track);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, content, start + 1);
	bytes_read = read(fd, content, file_size - start - 2);
	if (bytes_read == -1)
		return (NULL);
	content[bytes_read] = '\0';
	close(fd);
	return (content);
}

char	*get_symbols(char *fr_ln, t_mem *track)
{
	int		i;
	int		len;
	char	*symbols;

	symbols = ft_malloc(4, track);
	len = ft_strlen(fr_ln);
	i = 0;
	while (i < 3)
	{
		symbols[i] = fr_ln[len + i - 3];
		i++;
	}
	symbols[i] = '\0';
	return (symbols);
}

char	**input_parsing(char *content, int row, int column, t_mem *track)
{
	int		i;
	int		j;
	char	**map;

	map = ft_malloc((sizeof(char *) * row), track);
	i = 0;
	while (i < row)
		map[i++] = ft_malloc(column, track);
	j = 0;
	i = 0;
	while (*content)
	{
		if (*content == '\n')
		{
			map[i++][j] = '\0';
			j = 0;
		}
		else
			map[i][j++] = *content;
		content++;
	}
	return (map);
}
