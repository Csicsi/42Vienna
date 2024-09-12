/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:45:17 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/16 18:34:08 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet;

	alphabet = 'z';
	while (alphabet > 'a')
	{
		write(1, &alphabet, 1);
		alphabet--;
	}
	alphabet = 'a';
	write(1, &alphabet, 1);
}

/*int	main(void)
{
	ft_print_reverse_alphabet();
}*/
