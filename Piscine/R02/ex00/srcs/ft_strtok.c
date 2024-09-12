/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:53:17 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/02 12:44:30 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token = NULL;
	char		*token_start;
	char		*token;

	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);
	while (*next_token != '\0' && ft_strchr(delim, *next_token) != NULL)
		next_token++;
	if (*next_token == '\0')
		return (NULL);
	token_start = next_token;
	while (*next_token != '\0' && ft_strchr(delim, *next_token) == NULL)
		next_token++;
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	token = (char *)malloc((next_token - token_start + 1) * sizeof(char));
	if (token == NULL)
		return (NULL);
	ft_strcpy(token, token_start);
	return (token);
}
