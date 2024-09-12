/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:36:17 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/03 12:14:12 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(str, '\n'))
		str = parse_input(fd, str);
	if (!str || *str == '\0')
		return (free(str), str = NULL, NULL);
	line = extract_line(str);
	if (!line || !*line)
		return (free(line), free(str), line = NULL, str = NULL, NULL);
	temp = ft_strjoin(NULL, str + ft_strlen(line));
	if (!temp || !str)
		return (free(line), free(str), line = NULL, str = NULL, NULL);
	free(str);
	str = temp;
	return (line);
}
