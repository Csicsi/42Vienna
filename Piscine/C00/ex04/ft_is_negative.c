/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:08:08 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/16 19:16:32 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	n_or_p;

	if (n < 0)
	{
		n_or_p = 'N';
		write(1, &n_or_p, 1);
	}
	else
	{
		n_or_p = 'P';
		write(1, &n_or_p, 1);
	}
}

/*int	main(void)
{
	ft_is_negative(0);
}*/
