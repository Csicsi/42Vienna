/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:41:09 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/19 08:55:59 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcpy(char *dest, char *src)
{
	int	size;
	int	index;

	size = 0;
	index = 0;
	while (*src != '\0')
	{
		size++;
		src++;
	}
	src = src - size;
	while (index < size && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/*int main() {
    // Example strings
    char src[] = "Hello, world!";
    char dest[50]; // Make sure the destination array is large enough

    // Copying src to dest using ft_strcpy
    ft_strcpy(dest, src);

    // Printing the copied string
    printf("Copied string: %s\n", dest);

    return 0;
}*/
