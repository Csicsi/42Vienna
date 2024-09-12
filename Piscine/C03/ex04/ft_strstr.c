/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:40:32 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/19 18:19:10 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*pattern;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		start = str;
		pattern = to_find;
		while (*str && *pattern && *str == *pattern)
		{
			str++;
			pattern++;
		}
		if (*pattern == '\0')
			return (start);
		str = start + 1;
	}
	return (NULL);
}

/*int main()
{
    char str[] = "This is a test string";
    char to_find[] = "test";
    
    char *result = ft_strstr(str, to_find);
    
    if (result != NULL)
        printf("Substring found at index: %ld\n", result - str);
    else
        printf("Substring not found\n");
    
    return 0;
}*/
