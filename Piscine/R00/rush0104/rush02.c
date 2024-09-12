/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:11:45 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/17 12:28:05 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	hor;
	int	vert;

	vert = 1;
	while (vert <= y)
	{
		hor = 1;
		while (hor <= x)
		{
			if ((hor > 1 && hor < x) && (vert > 1 && vert < y))
				ft_putchar(' ');
			else if ((hor > 1 && hor < x) && (vert == 1 || vert == y))
				ft_putchar('B');
			else if ((hor == 1 || hor == x) && (vert > 1 && vert < y))
				ft_putchar('B');
			else if (vert == 1)
				ft_putchar('A');
			else
				ft_putchar('C');
			hor++;
		}
		ft_putchar('\n');
		vert++;
	}
}
