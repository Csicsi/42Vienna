/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:55:34 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 16:45:43 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_julia_properties(t_fractol *mlx, int px, int py)
{
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	zx = (px - WIDTH / 2.0) / mlx->zoom + mlx->x_center;
	zy = (py - HEIGHT / 2.0) / mlx->zoom + mlx->y_center;
	iter = 0;
	while (zx * zx + zy * zy < 4 && iter < mlx->julia.max_iter)
	{
		tmp = zx * zx - zy * zy + mlx->julia.real_c;
		zy = 2.0 * zx * zy + mlx->julia.imag_c;
		zx = tmp;
		iter++;
	}
	mlx->points[px + py * WIDTH].color = get_color(iter,
			mlx->julia.max_iter, mlx->color_shift);
	mlx->points[px + py * WIDTH].x = px;
	mlx->points[px + py * WIDTH].y = py;
}

void	julia(t_fractol *mlx)
{
	int		px;
	int		py;

	px = 0;
	while (px < WIDTH)
	{
		py = 0;
		while (py < HEIGHT)
		{
			set_julia_properties(mlx, px, py);
			py++;
		}
		px++;
	}
}
