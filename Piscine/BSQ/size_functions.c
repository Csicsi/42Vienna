/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:01:18 by icseri            #+#    #+#             */
/*   Updated: 2024/03/05 16:01:19 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_size(char *file_name, char sep, int occ)
{
	int		fd;
	int		total_bytes;
	char	buf[1];

	total_bytes = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, buf, 1) <= 0)
		return (-1);
	while (occ > 0)
	{
		if (buf[0] == sep)
			occ--;
		else
			total_bytes += 1;
		read(fd, buf, 1);
	}
	close(fd);
	return (total_bytes);
}

int	get_file_size(char *filename)
{
	int		fd;
	int		total_bytes;
	char	buf[1];

	total_bytes = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read(fd, buf, 1)) > 0)
		total_bytes += 1;
	close(fd);
	return (total_bytes);
}

int	get_row_count(char *fr_ln)
{
	int		i;
	int		len;
	int		row;

	len = ft_strlen(fr_ln);
	i = 0;
	row = 0;
	while (i < len - 3)
	{
		if (fr_ln[i] < '0' || fr_ln[i] > '9')
			return (-1);
		row *= 10;
		row += fr_ln[i] - 48;
		i++;
	}
	return (row);
}

int	get_column_count(char *file_name)
{
	return (get_size(file_name, '\n', 2) - get_size(file_name, '\n', 1) + 1);
}
