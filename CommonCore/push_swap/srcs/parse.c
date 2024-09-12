/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:32:43 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/08/11 11:59:26 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i + 1] == '-' || str[*i + 1] == '+')
			return (0);
		if (!ft_isdigit(str[*i + 1]))
			return (0);
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	is_valid_integer(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = handle_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (0);
		i++;
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static void	single_arg(t_stack *a, t_stack *b, char *arg)
{
	int		j;
	int		value;
	t_data	data;

	data.a = a;
	data.b = b;
	data.split = ft_split(arg, ' ');
	if (!data.split)
		handle_error(a, b);
	j = 0;
	while (data.split[j] != NULL)
		j++;
	while (j > 0)
	{
		j--;
		if (!is_valid_integer(data.split[j]))
		{
			free_split(data.split);
			handle_error(a, b);
		}
		value = ft_atoi(data.split[j]);
		push_a(value, 0, &data);
	}
	free_split(data.split);
}

static void	multiple_args(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		value;
	int		i;
	t_data	data;

	data.a = a;
	data.b = b;
	data.split = NULL;
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_integer(argv[i]))
		{
			free_stack(a);
			free(a);
			free(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		value = ft_atoi(argv[i]);
		push_a(value, 0, &data);
		i--;
	}
}

int	initialize(int argc, char **argv, t_stack **a, t_stack **b)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	if (!*a)
		return (0);
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (!*b)
	{
		free(*a);
		return (0);
	}
	init_stack(*a);
	init_stack(*b);
	if (argc == 2)
		single_arg(*a, *b, argv[1]);
	else
		multiple_args(*a, *b, argc, argv);
	return (1);
}
