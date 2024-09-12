/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:20:01 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/03 12:48:00 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fd_list	*get_fd_node(t_fd_list **head, int fd)
{
	t_fd_list	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_fd_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->str = NULL;
	node->next = *head;
	*head = node;
	return (node);
}

static void	remove_fd_node(t_fd_list **head, int fd)
{
	t_fd_list	*current;
	t_fd_list	*previous;

	current = *head;
	previous = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous)
				previous->next = current->next;
			else
				*head = current->next;
			free(current->str);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

static char	*parse_input(int fd, char *str)
{
	char	*buff;
	ssize_t	bytes;
	char	*temp;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str), NULL);
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		temp = ft_strjoin(str, buff);
		if (!temp)
			return (free(buff), free(str), NULL);
		free(str);
		str = temp;
		if (ft_strchr(str, '\n'))
			break ;
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (bytes == -1)
		return (free(str), NULL);
	return (str);
}

static char	*extract_line(char *str)
{
	size_t	len;
	char	*line;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, str, len);
	line[len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*head;
	t_fd_list			*fd_node;
	char				*line;
	char				*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_node = get_fd_node(&head, fd);
	if (!fd_node)
		return (NULL);
	if (!ft_strchr(fd_node->str, '\n'))
		fd_node->str = parse_input(fd, fd_node->str);
	if (!fd_node->str || *fd_node->str == '\0')
		return (remove_fd_node(&head, fd), NULL);
	line = extract_line(fd_node->str);
	if (!line || !*line)
		return (remove_fd_node(&head, fd), free(line), line = NULL, NULL);
	temp = ft_strjoin(NULL, fd_node->str + ft_strlen(line));
	if (!temp || !fd_node->str)
		return (remove_fd_node(&head, fd), free(line), line = NULL, NULL);
	free(fd_node->str);
	fd_node->str = temp;
	return (line);
}
