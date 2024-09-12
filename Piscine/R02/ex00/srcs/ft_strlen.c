/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:10:43 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/17 14:37:02 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(const char *str)
{
	int	temp;

	temp = 0;
	while (*str != '\0')
	{
		temp++;
		str++;
	}
	return (temp);
}

/*int	main(void)
{
	int	length;

	char str[] = "Hello, world!";
	length = ft_strlen(str);
	printf("%d", length);
	return (0);
}*/
