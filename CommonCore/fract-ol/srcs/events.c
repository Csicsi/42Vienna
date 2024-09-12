/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:28:04 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:51:36 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *mlx)
{
	if (keycode == ESC_KEY)
		safe_close(mlx);
	else if (keycode == KEY_SPACE)
		mlx->color_shift = (mlx->color_shift + 1) % 6;
	else if (keycode == ARROW_UP || keycode == KEY_W)
		mlx->y_center -= 20 / mlx->zoom;
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		mlx->y_center += 20 / mlx->zoom;
	else if (keycode == ARROW_LEFT || keycode == KEY_A)
		mlx->x_center -= 20 / mlx->zoom;
	else if (keycode == ARROW_RIGHT || keycode == KEY_D)
		mlx->x_center += 20 / mlx->zoom;
	else if (keycode == KEY_U)
		mlx->julia.real_c += 0.1;
	else if (keycode == KEY_J)
		mlx->julia.real_c -= 0.1;
	else if (keycode == KEY_I)
		mlx->julia.imag_c += 0.1;
	else if (keycode == KEY_K)
		mlx->julia.imag_c -= 0.1;
	fill_pixels(mlx);
	render(mlx);
	return (0);
}

static void	update_zoom_center(t_fractol *mlx, int x, int y, double zoom_factor)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = mlx->x_center + (x - WIDTH / 2.0) / mlx->zoom;
	mouse_y = mlx->y_center + (y - HEIGHT / 2.0) / mlx->zoom;
	mlx->zoom *= zoom_factor;
	mlx->x_center = mouse_x - (x - WIDTH / 2.0) / mlx->zoom;
	mlx->y_center = mouse_y - (y - HEIGHT / 2.0) / mlx->zoom;
}

static int	calculate_iter_change(t_fractol *mlx, int button)
{
	int	iter_change;

	iter_change = (int)(log(mlx->zoom) / (60 * log(1.2)));
	if (button == SCROLL_DOWN)
		iter_change = -iter_change;
	return (iter_change);
}

static void	update_iterations(t_fractol *mlx, int iter_change)
{
	mlx->julia.max_iter += iter_change;
	if (mlx->julia.max_iter < 0)
		mlx->julia.max_iter = 0;
	mlx->mandelbrot.max_iter += iter_change;
	if (mlx->mandelbrot.max_iter < 0)
		mlx->mandelbrot.max_iter = 0;
}

int	mouse_hook(int button, int x, int y, t_fractol *mlx)
{
	double	zoom_factor;
	int		iter_change;

	if (button == SCROLL_UP)
		zoom_factor = 1.2;
	else if (button == SCROLL_DOWN)
		zoom_factor = 1.0 / 1.2;
	else
		return (0);
	update_zoom_center(mlx, x, y, zoom_factor);
	iter_change = calculate_iter_change(mlx, button);
	update_iterations(mlx, iter_change);
	fill_pixels(mlx);
	render(mlx);
	return (0);
}
