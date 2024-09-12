/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:59:13 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/13 18:42:39 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	count_words(char *str, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (*str == c && in_word)
			in_word = 0;
		str++;
	}
	return (words);
}

static void	copy_word(char *dest, char *src, char c)
{
	while (*src && *src != c)
		*dest++ = *src++;
	*dest = '\0';
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	split_words(char **split, char *str, char c)
{
	char	*start;
	int		length;

	while (*str)
	{
		if (*str != c)
		{
			start = str;
			length = 0;
			while (*str && *str != c && ++length)
				str++;
			*split = malloc(length + 1);
			if (!*split)
			{
				free_split(split);
				return (-1);
			}
			copy_word(*split++, start, c);
		}
		else
			str++;
	}
	*split = NULL;
	return (0);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		words;

	words = count_words(str, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (split_words(result, str, c) == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
