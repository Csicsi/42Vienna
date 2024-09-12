/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalajqi <lalajqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:15:45 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/03 22:04:48 by lalajqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_line(int fd, char *line, int max_length)
{
	int		index;
	char	ch;

	index = 0;
	while (read(fd, &ch, 1) == 1 && ch != '\n' && index < max_length)
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return (index);
}

t_dict	*create_dictionary(void)
{
	t_dict	*dictionary;

	dictionary = (t_dict *)malloc(sizeof(t_dict));
	if (dictionary == NULL)
	{
		return (NULL);
	}
	dictionary->entries = (t_entry *)malloc(MAX_ENTRIES * sizeof(t_entry));
	if (dictionary->entries == NULL)
	{
		free(dictionary);
		return (NULL);
	}
	dictionary->size = 0;
	return (dictionary);
}

int	populate_dictionary(int fd, t_dict *dictionary)
{
	char	line[MAX_LINE_LENGTH];
	char	*token;
	int		index;

	index = 0;
	while (index < MAX_ENTRIES
		&& read_line(fd, line, MAX_LINE_LENGTH) > 0)
	{
		token = ft_strtok(line, ":");
		if (token != NULL)
		{
			dictionary->entries[index].key = ft_strdup(token);
			token = ft_strtok(NULL, ":");
			if (token != NULL)
			{
				dictionary->entries[index].value = ft_strdup(token);
				index++;
			}
		}
	}
	dictionary->size = index;
	return (1);
}

void	free_dictionary(t_dict *dictionary)
{
	int	index;

	index = 0;
	if (dictionary == NULL)
		return ;
	while (index < dictionary->size)
	{
		free(dictionary->entries[index].key);
		free(dictionary->entries[index].value);
		index++;
	}
	free(dictionary->entries);
	free(dictionary);
}

t_dict	*parse_dictionary(const char *filename)
{
	int		fd;
	t_dict	*dictionary;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening the file\n", 23);
		return (NULL);
	}
	dictionary = create_dictionary();
	if (dictionary == NULL)
	{
		close(fd);
		return (NULL);
	}
	if (!populate_dictionary(fd, dictionary))
	{
		free_dictionary(dictionary);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (dictionary);
}
