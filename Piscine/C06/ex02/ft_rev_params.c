/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:13:15 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/22 18:49:55 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	index;

	while (argc > 1)
	{
		index = 0;
		while (argv[argc - 1][index])
		{
			ft_putchar(argv[argc - 1][index]);
			index++;
		}
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
