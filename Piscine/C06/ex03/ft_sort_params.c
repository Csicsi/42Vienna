/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:33:38 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/25 22:51:32 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_params(int argc, char **argv)
{
	int		index1;
	int		index2;
	char	*temp;

	index1 = 1;
	while (index1 < argc - 1)
	{
		index2 = index1 + 1;
		while (index2 < argc)
		{
			if (ft_strcmp(argv[index1], argv[index2]) > 0)
			{
				temp = argv[index1];
				argv[index1] = argv[index2];
				argv[index2] = temp;
			}
			index2++;
		}
		index1++;
	}
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		index;

	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		index = 1;
		while (index < argc)
		{
			arg = argv[index];
			while (*arg)
			{
				ft_putchar(*arg);
				arg++;
			}
			ft_putchar('\n');
			index++;
		}
	}
	return (0);
}
