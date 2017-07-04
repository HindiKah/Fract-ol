#include "../includes/fractol.h"

int		count_mandelbrot(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->iter_max)
	{
		e->draw->tmp = e->draw->zr;
		e->draw->zr = e->draw->zr * e->draw->zr - e->draw->zi * e->draw->zi + e->draw->cr;
		e->draw->zi = 2 * e->draw->zi * e->draw->tmp + e->draw->ci;
		if (e->draw->zr * e->draw->zr + e->draw->zi * e->draw->zi >= 4)
			return (i);
	}
	return (i);
}

void			fractal_mandelbrot(t_env *e)
{
	intmax_t	x;
	intmax_t	y;

	x = e->x;
	while (++x < WIN_X + e->x)
	{
		y = e->y;
		while (++y < WIN_Y + e->y)
		{
			e->draw->zr = 0;
			e->draw->zi = 0;
			e->draw->cr = (long double)x / e->z + e->draw->x1;
			e->draw->ci = (long double)y / e->z + e->draw->y1;
			put_pixel(e, x - e->x, y - e->y, give_color(e, count_mandelbrot(e)));
		}
	}
	mlx_put_image_to_window(e->mlx_p, e->win, e->img_p, 0, 0);
}
