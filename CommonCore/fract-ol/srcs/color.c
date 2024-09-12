/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:41:13 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:29:42 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

static void	calculate_rgb(double t, int *r, int *g, int *b)
{
	*r = (int)(9 * (1 - t) * t * t * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*r = clamp(*r, 0, 255);
	*g = clamp(*g, 0, 255);
	*b = clamp(*b, 0, 255);
}

static int	apply_color_shift(int r, int g, int b, int color_shift)
{
	if (color_shift == 1)
		return ((g << 16) | (b << 8) | r);
	if (color_shift == 2)
		return ((b << 16) | (r << 8) | g);
	if (color_shift == 3)
		return ((r << 16) | (b << 8) | g);
	if (color_shift == 4)
		return ((g << 16) | (r << 8) | b);
	if (color_shift == 5)
		return ((b << 16) | (g << 8) | r);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iter, int max_iter, int color_shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	calculate_rgb(t, &r, &g, &b);
	return (apply_color_shift(r, g, b, color_shift));
}
