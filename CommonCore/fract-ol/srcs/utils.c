/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:31:25 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:57:04 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_points(t_fractol *mlx)
{
	if (mlx->points)
		free(mlx->points);
}

int	safe_close(t_fractol *mlx)
{
	free_points(mlx);
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx, mlx->img_ptr);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	exit(0);
	return (0);
}

void	allocate_points(t_fractol *mlx)
{
	mlx->points = (t_pixel *)malloc(sizeof(t_pixel) * WIDTH * HEIGHT);
	if (mlx->points == NULL)
		safe_close(mlx);
}

void	put_controls(t_fractol *mlx, int pos, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, pos, 0xFFFFFF, str);
}
