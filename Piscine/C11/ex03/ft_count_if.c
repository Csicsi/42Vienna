/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:07:19 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/03 13:12:11 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < length)
	{
		if ((*f)(tab[index]))
			count++;
		index++;
	}
	return (count);
}
