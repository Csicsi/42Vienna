/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:48:03 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/28 22:15:51 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_capitalize(char *str)
{
	int	index;
	int	capitalize;

	index = 0;
	capitalize = 1;
	while (str[index])
	{
		if ((str[index] >= 'a' && str[index] <= 'z') && capitalize)
		{
			str[index] = str[index] - 32;
			capitalize = 0;
		}
		else if (str[index] < '0' || (str[index] > '9' && str[index] < 'A')
			|| (str[index] > 'Z' && str[index] < 'a')
			|| str[index] > 'z')
			capitalize = 1;
		if (str[index] > '0' && str[index] < '9')
			capitalize = 0;
		index++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	capitalize;

	index = 0;
	capitalize = 1;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	index = 0;
	ft_capitalize(str);
	return (str);
}

/*int main()
{
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    printf("Original string: %s\n", str);
    printf("Capitalized string: %s\n", ft_strcapitalize(str)); 
    return 0;
}*/
