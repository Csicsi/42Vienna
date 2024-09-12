/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:59:13 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/16 14:25:26 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
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

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

static int	find_next_word(char **start, int *length, const char *str, char c)
{
	*start = NULL;
	*length = 0;
	while (*str && *str == c)
		str++;
	if (*str)
	{
		*start = (char *)str;
		while (*str && *str != c)
		{
			(*length)++;
			str++;
		}
		return (1);
	}
	return (0);
}

static int	split_words(char **split, const char *str, char c)
{
	char	*start;
	int		length;
	int		index;

	index = 0;
	while (find_next_word(&start, &length, str, c))
	{
		split[index] = malloc(length + 1);
		if (!split[index])
		{
			free_split(split);
			return (-1);
		}
		ft_strlcpy(split[index], start, length + 1);
		split[index][length] = '\0';
		str = start + length;
		index++;
	}
	split[index] = NULL;
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		words;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	if (words == 0)
	{
		result = (char **)malloc(sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (split_words(result, str, c) == -1)
		return (NULL);
	return (result);
}
