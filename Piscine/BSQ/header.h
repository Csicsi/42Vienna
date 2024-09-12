/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:14:40 by icseri            #+#    #+#             */
/*   Updated: 2024/03/06 16:32:26 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_crd
{
	int		x;
	int		y;
	int		size;
	char	obs;
}	t_crd;

typedef struct s_map
{
	char	**map;
	int		row;
	int		column;
}	t_map;

typedef struct s_mem
{
	void	**allocated_memory;
	size_t	allocated_count;
	size_t	allocated_capacity;
}	t_mem;

void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_putchar(char str);
void		ft_puterror(char *str);
int			get_size(char *file_name, char sep, int occ);
int			get_file_size(char *filename);
char		*get_first_line(char *file_name, t_mem *trac);
char		*get_file_content(char *file_name, t_mem *trac);
char		*get_symbols(char *file_name, t_mem *trac);
int			get_row_count(char *fr_ln);
int			get_column_count(char *file_name);
char		**input_parsing(char *file_name, int row, int column, t_mem *trac);
int			map_check(char	*file_name, t_mem *trac);
void		solve(t_map map, t_crd *top_lft, int *max, char *symbols);
void		drawing_square(t_map map, t_crd top_lft, int max, char full);
void		prnt_sq(char *file_name, t_crd row_col, char *symbols, t_mem *trac);
int			stdin_col_count(char *buffer);
int			stdin_row_count(char *buffer);
char		*stdin_first_line(char *buffer, t_mem *trac);
char		*stdin_map(const char *buffer, t_mem *trac);
int			stdin_chk(char *fr_ln, char *content, t_crd row_col, t_mem *trac);
char		*ft_realloc(char *buffer, size_t old_s, size_t new_s, t_mem *trac);
const char	*find_newline(const char *buffer);
char		*read_input(t_mem *trac);
void		*ft_malloc(size_t size, t_mem *trac);
void		init_alloc(t_mem *trac);
void		free_all(t_mem *trac);

#endif
