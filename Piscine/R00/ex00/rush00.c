/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:15:05 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/17 12:22:32 by dcsicsak         ###   ########.fr       */
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
				ft_putchar('-');
			else if ((hor == 1 || hor == x) && (vert > 1 && vert < y))
				ft_putchar('|');
			else
				ft_putchar('o');
			hor++;
		}
		ft_putchar('\n');
		vert++;
	}
}
