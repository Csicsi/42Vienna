/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:21:19 by icseri            #+#    #+#             */
/*   Updated: 2024/03/06 16:19:55 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	src_is_file(int argc, char *argv[], t_mem *track)
{
	int		i;
	t_crd	row_col;
	char	*symbols;

	i = 1;
	while (i < argc)
	{
		if (!(map_check(argv[i], track) == 0))
		{
			symbols = get_symbols(get_first_line(argv[i], track), track);
			row_col.x = get_row_count(get_first_line(argv[i], track));
			row_col.y = get_column_count(argv[i]) - 1;
			prnt_sq(get_file_content(argv[i], track), row_col, symbols, track);
			if (i < argc - 1)
				write(1, "\n", 1);
		}
		i++;
	}
}

void	src_is_stdin(t_mem *track)
{
	t_crd	row_col;
	char	*fr_ln;
	char	*content;
	char	*buffer;

	buffer = read_input(track);
	if (buffer[0] == '\0')
	{
		ft_puterror("map error\n");
		return ;
	}
	row_col.y = stdin_col_count(buffer);
	row_col.x = stdin_row_count(buffer);
	fr_ln = stdin_first_line(buffer, track);
	content = stdin_map(buffer, track);
	if (stdin_chk(fr_ln, content, row_col, track) == 0)
	{
		return ;
	}
	else
	{
		prnt_sq(content, row_col, get_symbols(fr_ln, track), track);
	}
}

int	main(int argc, char **argv)
{
	t_mem	track;

	init_alloc(&track);
	if (argc == 1)
	{
		src_is_stdin(&track);
	}
	else
	{
		src_is_file(argc, argv, &track);
	}
	free_all(&track);
	return (0);
}
