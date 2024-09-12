/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcosmin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:11:38 by vcosmin           #+#    #+#             */
/*   Updated: 2024/02/17 15:44:35 by oshcheho         ###   ########.fr       */
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
				ft_putchar('*');
			else if ((hor == 1 || hor == x) && (vert > 1 && vert < y))
				ft_putchar('*');
			else if ((hor == 1 && vert == 1) || (hor == x && vert == y))
				ft_putchar('/');
			else
				ft_putchar('\\');
			hor++;
		}
		vert++;
		ft_putchar('\n');
	}
}
