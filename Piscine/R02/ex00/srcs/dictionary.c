/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpanic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:22:12 by vpanic            #+#    #+#             */
/*   Updated: 2024/03/02 14:22:17 by vpanic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*lookup_value(char *key, t_dict *dictionary)
{
	if (dictionary == NULL || key == NULL)
	{
	write(2, "Error: Invalid dictionary or key\n", 34);
	return NULL;
	}
	else
	{	
		int	i;

		i = 0;
		while (i < dictionary -> size)
		{
			if (ft_strcmp(dictionary -> entries[i].key, key) == 0)
				return (dictionary -> entries[i].value);
			i++;
		}
		write(2, "Error: Key not found in dictionary\n", 36);
		return (NULL);
	}
}

void	convert_tens_ones(int number, t_dict *dictionary, char *result)
{
	char	*tensStr;
	int		tens;
	int		ones;
	
	tens = (number / 10) * 10;
	ones = number % 10;
	printf("Debug: Tens: %d, Ones: %d\n", tens, ones);  // Add this line for debugging
	if (tens > 0)
	{
		tensStr = lookup_value(ft_itoa(tens), dictionary);
		if (tensStr != NULL)
		{	
			printf("Debug: TensStr: %s\n", tensStr);  // Add this line for debugging
			ft_strcat(result, tensStr);
			 if (ones > 0)
			 {
			 ft_strcat(result, " ");
			 convert_tens_ones(ones, dictionary, result);
			 }
		}
	}
	else
	{
		write(2, "Error: Conversion failed for tens place\n", 41);
		return;
	}
}

char	*con_lett(int number, t_dict *dictionary)
{
	char	*result;

	if (number < 0)
	{
		write(2, "Error: Number out of range\n", 27);
		return (NULL);
	}	
	result = malloc(MAX_LINE_LENGTH);
	if (!result)
	{
	 	write(2, "Error: Memory allocation failed\n", 32);
		return (NULL);
	}
	if (number == 0 || number == 1)
	{
		ft_strcat(result, lookup_value(ft_itoa(number), dictionary));
	}
	if (number >= 1 && number <= 19)
		ft_strcat(result, lookup_value(ft_itoa(number), dictionary));
	else if (number >= 20 && number <= 99)
	{
		convert_tens_ones(number, dictionary, result);
	}
	else
	{
		write(2, "Error: Number out of supported range\n", 38);
		free (result);
		return (NULL);
	}
	return (result);
}
