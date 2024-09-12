/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:28:42 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:35:35 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mlx(t_fractol *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FdF");
	if (!mlx->win)
	{
		safe_close(mlx);
		return (0);
	}
	return (1);
}

static void	init_fdf(t_fractol *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img_ptr = NULL;
	mlx->points = NULL;
	mlx->zoom = 400.0;
	mlx->x_center = -0.5;
	mlx->y_center = 0.0;
	mlx->render_type = -1;
	mlx->color_shift = 0;
	mlx->mandelbrot.max_iter = 30;
	mlx->julia.max_iter = 30;
}

int	main(int argc, char *argv[])
{
	t_fractol	mlx;

	init_fdf(&mlx);
	if (!init_mlx(&mlx))
		return (0);
	allocate_points(&mlx);
	parse_arguments(argc, argv, &mlx);
	fill_pixels(&mlx);
	render(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, safe_close, &mlx);
	mlx_loop(mlx.mlx);
	free_points(&mlx);
	return (0);
}
