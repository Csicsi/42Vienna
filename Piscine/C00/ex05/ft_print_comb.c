/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:23:04 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/27 11:13:14 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	hundreds;
	char	tens;
	char	ones;

	hundreds = '0';
	while (hundreds <= '7')
	{
		tens = hundreds + 1;
		while (tens <= '8')
		{
			ones = tens + 1;
			while (ones <= '9')
			{
				write(1, &hundreds, 1);
				write(1, &tens, 1);
				write(1, &ones, 1);
				if (!(hundreds == '7' && tens == '8' && ones == '9'))
					write(1, ", ", 2);
				ones++;
			}
			tens++;
		}
		hundreds++;
	}
}

/*int	main(void)
{
	ft_print_comb();
}*/
