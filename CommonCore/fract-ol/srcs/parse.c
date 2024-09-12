/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:04:16 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:30:55 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_float(const char *str)
{
	int	i;
	int	dot_count;
	int	digit_count;

	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (ft_isdigit(str[i]))
			digit_count++;
		else
			return (0);
		i++;
	}
	return (digit_count > 0);
}

static void	print_usage(const char *program_name, t_fractol *mlx)
{
	ft_printf("Usage: %s <FractalType> [arguments]\n", program_name);
	ft_printf("FractalType:\n");
	ft_printf("  Julia, J, j, 1 : Render the Julia set. Optionally, provide\n");
	ft_printf("                  real and imaginary constants.\n");
	ft_printf("                   Example: %s Julia -0.7 0.27\n", program_name);
	ft_printf("  Mandelbrot, M, m, 0 : Render the Mandelbrot set.");
	ft_printf(" No additional arguments needed.\n");
	ft_printf("                   Example: %s Mandelbrot\n", program_name);
	ft_printf("  Burning ship, B, b, 2 : Render the Burning Ship.");
	ft_printf(" No additional arguments needed.\n");
	ft_printf("                   Example: %s Burning ship\n", program_name);
	safe_close(mlx);
}

static void	set_julia_params(int argc, char *argv[], t_fractol *mlx)
{
	if (argc == 2)
	{
		mlx->julia.real_c = -0.7;
		mlx->julia.imag_c = 0.27015;
	}
	else if (argc == 4)
	{
		if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
			print_usage(argv[0], mlx);
		mlx->julia.real_c = ft_atof(argv[2]);
		mlx->julia.imag_c = ft_atof(argv[3]);
	}
	else
		print_usage(argv[0], mlx);
}

static void	set_render_type(int argc, char *argv[], t_fractol *mlx)
{
	if (ft_strcmp(argv[1], "Julia") == 0 || ft_strcmp(argv[1], "J") == 0
		|| ft_strcmp(argv[1], "j") == 0 || ft_strcmp(argv[1], "1") == 0)
	{
		mlx->render_type = 1;
		set_julia_params(argc, argv, mlx);
	}
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0
		|| ft_strcmp(argv[1], "M") == 0
		|| ft_strcmp(argv[1], "m") == 0 || ft_strcmp(argv[1], "0") == 0)
	{
		mlx->render_type = 0;
		if (argc != 2)
			print_usage(argv[0], mlx);
	}
	else if (ft_strcmp(argv[1], "Burning ship") == 0
		|| ft_strcmp(argv[1], "B") == 0
		|| ft_strcmp(argv[1], "b") == 0 || ft_strcmp(argv[1], "2") == 0)
	{
		mlx->render_type = 2;
		if (argc != 2)
			print_usage(argv[0], mlx);
	}
	else
		print_usage(argv[0], mlx);
}

void	parse_arguments(int argc, char *argv[], t_fractol *mlx)
{
	if (argc < 2)
	{
		print_usage(argv[0], mlx);
		safe_close(mlx);
	}
	else
	{
		set_render_type(argc, argv, mlx);
	}
}
