/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:27:07 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:59:58 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_controls(t_fractol *mlx)
{
	int	y;
	int	offset;

	y = 10;
	offset = 20;
	put_controls(mlx, y, "Controls:");
	y += offset;
	put_controls(mlx, y, "W or Up Arrow - Move Up");
	y += offset;
	put_controls(mlx, y, "A or Left Arrow - Move Left");
	y += offset;
	put_controls(mlx, y, "S or Down Arrow - Move Down");
	y += offset;
	put_controls(mlx, y, "D or Right Arrow - Move Right");
	y += offset;
	put_controls(mlx, y, "Space - Shift colors");
	y += offset;
	put_controls(mlx, y, "U or J - Shift Julia Real Part");
	y += offset;
	put_controls(mlx, y, "I or K - Shift Julia Imaginary Part");
	y += offset;
	put_controls(mlx, y, "Mouse Wheel - Zoom");
	y += offset;
	put_controls(mlx, y, "ESC - Exit");
}

void	fill_pixels(t_fractol *mlx)
{
	if (mlx->render_type == -1)
		safe_close(mlx);
	else if (mlx->render_type == 0)
		mandelbrot(mlx);
	else if (mlx->render_type == 1)
		julia(mlx);
	else if (mlx->render_type == 2)
		burning_ship(mlx);
	else
		safe_close(mlx);
}

static void	put_pixel_to_image(t_fractol *mlx, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = (y * mlx->size_line) + (x * (mlx->bpp / 8));
		mlx->img_data[pixel] = color;
		mlx->img_data[pixel + 1] = color >> 8;
		mlx->img_data[pixel + 2] = color >> 16;
	}
}

static void	draw_points_to_image(t_fractol *mlx)
{
	int	i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		put_pixel_to_image(mlx, mlx->points[i].x,
			mlx->points[i].y, mlx->points[i].color);
		i++;
	}
}

void	render(t_fractol *mlx)
{
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img_ptr == NULL)
		safe_close(mlx);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	draw_points_to_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr, 0, 0);
	display_controls(mlx);
}
