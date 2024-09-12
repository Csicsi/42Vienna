/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:32:04 by csicsi            #+#    #+#             */
/*   Updated: 2024/06/22 14:31:53 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	int		i;
	int		j;
	int		len;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len += gnl_strlen(s1);
	if (s2)
		len += gnl_strlen(s2);
	joined_str = malloc(len + 1);
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		joined_str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		joined_str[i++] = s2[j++];
	joined_str[i] = '\0';
	return (joined_str);
}

void	safe_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
