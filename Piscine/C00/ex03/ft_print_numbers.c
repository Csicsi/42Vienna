/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:03:34 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/16 18:40:23 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digit;

	digit = '0';
	while (digit < '9')
	{
		write(1, &digit, 1);
		digit++;
	}
	digit = '9';
	write(1, &digit, 1);
}

/*int	main(void)
{
	ft_print_numbers();
}*/
