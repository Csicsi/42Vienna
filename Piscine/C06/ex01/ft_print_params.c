/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:13:15 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/22 19:00:53 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	arg;
	int	index;

	(void)argc;
	arg = 1;
	while (argv[arg])
	{
		index = 0;
		while (argv[arg][index])
		{
			ft_putchar(argv[arg][index]);
			index++;
		}
		write(1, "\n", 1);
		arg++;
	}
	return (0);
}
