#include "../includes/fractol.h"

int			count_mine(t_env *e)
{
	int		i;

	i = -1;
	e->iter_max = 50;
	while (++i < e->iter_max)
	{
		e->draw->tmp = e->draw->zr;
		e->draw->zr = e->draw->zi * e->draw->zr - e->draw->zi * e->draw->zi - 0.85 + (0.5 / ((double)e->x_2 / (double)WIN_X));
		e->draw->zi = 3 * e->draw->zi * e->draw->tmp + 0.25 /
			((double)e->y_2 / (double)WIN_Y);
		if (e->draw->zr * e->draw->zr + e->draw->zi * e->draw->zi >= 150)
			return (i);
	}
	return (i);
}

void		fractal_mine(t_env *e)
{
	intmax_t x;
	intmax_t y;

	x = e->x;
	y = e->y;
	while (++x < WIN_X + e->x)
	{
		y = e->y;
		while (++y < WIN_Y + e->y)
		{
			e->draw->zr = (long double)x / e->z + e->draw->x1;
			e->draw->zi = (long double)y / e->z + e->draw->y1;
			put_pixel(e, x - e->x, y - e->y, give_color(e, count_mine(e)));
		}
	}
	mlx_put_image_to_window(e->mlx_p, e->win, e->img_p, 0, 0);
}
