/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:42:36 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/28 22:49:05 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			ft_putchar(*str);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[*str / 16]);
			ft_putchar("0123456789abcdef"[*str % 16]);
		}
		str++;
	}
}

/*int main()
{
    char str[] = "Coucou\ntu vas bien ?";

    printf("Original string: %s\n", str);
    printf("Printing non-printable characters:\n");
    ft_putstr_non_printable(str);

    return 0;
}*/
