/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:12:05 by oshcheho          #+#    #+#             */
/*   Updated: 2024/02/17 16:51:54 by oshcheho         ###   ########.fr       */
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
			else if (hor == 1)
				ft_putchar('A');
			else
				ft_putchar('C');
			hor++;
		}
		ft_putchar('\n');
		vert++;
	}
}
