/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:17:19 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 16:57:54 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_mandelbrot_properties(t_fractol *mlx, int px, int py)
{
	t_mandelbrot	mb;

	mb.cx = (px - WIDTH / 2.0) / mlx->zoom + mlx->x_center;
	mb.cy = (py - HEIGHT / 2.0) / mlx->zoom + mlx->y_center;
	mb.zx = 0;
	mb.zy = 0;
	mb.iter = 0;
	while (mb.zx * mb.zx + mb.zy * mb.zy < 4
		&& mb.iter < mlx->mandelbrot.max_iter)
	{
		mb.tmp = mb.zx * mb.zx - mb.zy * mb.zy + mb.cx;
		mb.zy = 2.0 * mb.zx * mb.zy + mb.cy;
		mb.zx = mb.tmp;
		mb.iter++;
	}
	mlx->points[px + py * WIDTH].color
		= get_color(mb.iter, mlx->mandelbrot.max_iter, mlx->color_shift);
	mlx->points[px + py * WIDTH].x = px;
	mlx->points[px + py * WIDTH].y = py;
}

void	mandelbrot(t_fractol *mlx)
{
	int	px;
	int	py;

	px = 0;
	while (px < WIDTH)
	{
		py = 0;
		while (py < HEIGHT)
		{
			set_mandelbrot_properties(mlx, px, py);
			py++;
		}
		px++;
	}
}
