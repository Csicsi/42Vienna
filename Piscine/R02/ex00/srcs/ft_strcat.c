/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:44:14 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/19 17:05:10 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	dest_size;
	int	index;

	dest_size = 0;
	index = 0;
	while (dest[dest_size])
	{
		dest_size++;
	}
	while (src[index])
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest);
}

/*int main()
{
    // Example strings
    char src[] = "Hello, world!";
    char dest[50] = "Test:"; // Make sure the destination array is large enough

    // Copying src to dest using ft_strcpy
    ft_strcat(dest, src);

    // Printing the copied string
    printf("Copied string: %s\n", dest);

    return 0;
}*/
