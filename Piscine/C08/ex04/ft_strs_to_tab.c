/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:57:10 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/01 11:33:43 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	temp;

	temp = 0;
	while (*str != '\0')
	{
		temp++;
		str++;
	}
	return (temp);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (index < ft_strlen(src) && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					index;

	tab = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (tab == NULL)
	{
		return (NULL);
	}
	index = 0;
	while (index < ac)
	{
		tab[index].size = ft_strlen(av[index]);
		tab[index].str = av[index];
		tab[index].copy = ft_strdup(av[index]);
		index++;
	}
	tab[index].str = 0;
	return (tab);
}
