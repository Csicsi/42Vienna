/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:18:34 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/28 20:35:49 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index1;
	unsigned int	index2;
	unsigned int	res;

	index1 = 0;
	index2 = 0;
	res = 0;
	while (dest[index1])
		index1++;
	while (src[res])
		res++;
	if (size <= index1)
		res += size;
	else
		res += index1;
	while (src[index2] && (index1 + 1) < size)
	{
		dest[index1] = src[index2];
		index1++;
		index2++;
	}
	dest[index1] = '\0';
	return (res);
}
