/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:26 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/16 18:29:48 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alphabet;

	alphabet = 'a';
	while (alphabet < 'z' )
	{
		write(1, &alphabet, 1);
		alphabet++;
	}
	alphabet = 'z';
	write(1, &alphabet, 1);
}

/*int	main(void)
{
	ft_print_alphabet();
}*/
