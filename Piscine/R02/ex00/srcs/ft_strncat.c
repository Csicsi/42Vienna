/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:44:14 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/19 18:16:39 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_size;
	int	index;

	dest_size = 0;
	index = 0;
	while (dest[dest_size])
	{
		dest_size++;
	}
	while (nb && src[index])
	{
		dest[dest_size + index] = src[index];
		index++;
		nb--;
	}
	dest[dest_size + index] = '\0';
	return (dest);
}

/*int main()
{
    // Example strings
    char src[] = "Hello, world!";
    char dest[50] = "Testing: ";

    // Copying src to dest using ft_strcpy
    ft_strncat(dest, src, 5);

    // Printing the copied string
    printf("Copied string: %s\n", dest);

    return 0;
}*/
