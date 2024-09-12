/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:17:42 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/03 13:32:23 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	ascend;
	int	descend;

	index = 0;
	ascend = 1;
	descend = 1;
	while (index < length - 1 && (ascend || descend))
	{
		if ((*f)(tab[index], tab[index + 1]) > 0)
			ascend = 0;
		else if ((*f)(tab[index], tab[index + 1]) < 0)
			descend = 0;
		index++;
	}
	return (ascend || descend);
}
