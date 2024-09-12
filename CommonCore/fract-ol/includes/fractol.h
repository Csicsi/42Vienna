/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:38:15 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/06/22 17:56:59 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

# define WIDTH 1700
# define HEIGHT 900

# define ESC_KEY 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_SPACE 32
# define KEY_I 105
# define KEY_K 107
# define KEY_U 117
# define KEY_J 106

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_julia
{
	double	real_c;
	double	imag_c;
	int		max_iter;
	double	zx;
	double	zy;
	double	tmp;
	int		iter;
}	t_julia;

typedef struct s_mandelbrot
{
	int		max_iter;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp;
	int		iter;
}	t_mandelbrot;

typedef struct s_koch
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		depth;
}	t_koch;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	t_pixel			*points;
	double			zoom;
	double			x_center;
	double			y_center;
	int				render_type;
	t_julia			julia;
	t_mandelbrot	mandelbrot;
	int				color_shift;
}	t_fractol;

void	render(t_fractol *mlx);
int		mouse_hook(int button, int x, int y, t_fractol *mlx);
int		key_hook(int keycode, t_fractol *mlx);
void	free_points(t_fractol *mlx);
int		safe_close(t_fractol *mlx);
void	allocate_points(t_fractol *mlx);
void	fill_pixels(t_fractol *mlx);
void	julia(t_fractol *mlx);
void	mandelbrot(t_fractol *mlx);
int		get_color(int iter, int max_iter, int color_shift);
void	parse_arguments(int argc, char *argv[], t_fractol *mlx);
void	burning_ship(t_fractol *mlx);
void	put_controls(t_fractol *mlx, int pos, char *str);

#endif
