#include "../includes/fractol.h"

void		init_julia(t_fractal *draw)
{
	draw->x1 = -2.1;
	draw->x2 = 0.6;
	draw->y1 = -1.2;
	draw->y2 = 1.2;
	draw->zr = 0;
	draw->zi = 0;
	draw->cr = 0;
	draw->ci = 0;
	draw->tmp = 0;
}
int			count_julia(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->iter_max)
	{
		e->draw->tmp = e->draw->zr;
		e->draw->zr = e->draw->zr * e->draw->zr - e->draw->zi * e->draw->zi - 0.8 +
			(0.6 / ((double)e->x_2 / (double)WIN_X));
		e->draw->zi = 2 * e->draw->zi * e->draw->tmp + 0.27015 /
			((double)e->y_2 / (double)WIN_Y);
		//printf("2->>e->x = %jd e->y = %jd e->draw -> draw->x1 = %LF draw->x2 = %LF draw->y1 = %LF draw->y2 = %LF draw->zr = %LF draw->zi = %LFdraw->cr = %LF draw->ci = %LF draw->tmp = %LF e->x2 = %d e->y2 = %d\n\n", e->x, e->y ,e->draw->x1, e->draw->x2,e->draw->y1, e->draw->y2, e->draw->zr, e->draw->zi, e->draw->cr, e->draw->ci, e->draw->tmp, e->x_2, e->y_2);
		if (e->draw->zr * e->draw->zr + e->draw->zi * e->draw->zi >= 4)
			return (i);
	}
	return (i);
}

void			fractal_julia(t_env *e)
{
	intmax_t x;
	intmax_t y;

	x = e->x;
	y = e->y;
	//printf("1->>ju zr = %LF && ju zi = %LF z  = %jd win y = %d && itermax = %d && e->x = %jd e->y = %jd x = %jd y = %jd\n\n", e->draw->zr, e->draw->zi, e->z, WIN_Y, e->iter_max, e->x, e->y, x, y);
	//printf("1->>e->draw ->\n draw->x1 = %LF draw->x2 = %LF draw->y1 = %LF draw->y2 = %LF draw->zr = %LF draw->zi = %LFdraw->cr = %LF draw->ci = %LF draw->tmp = %LF\n\n", e->draw->x1, e->draw->x2,e->draw->y1, e->draw->y2, e->draw->zr, e->draw->zi, e->draw->cr, e->draw->ci, e->draw->tmp);
	while (++x < WIN_X + e->x)
	{
		y = e->y;
		while (++y < WIN_Y + e->y)
		{
			e->draw->zr = (long double)x / e->z + e->draw->x1;
			e->draw->zi = (long double)y / e->z + e->draw->y1;
			put_pixel(e, x - e->x, y - e->y, give_color(e, count_julia(e)));
		}
	}
	mlx_put_image_to_window(e->mlx_p, e->win, e->img_p, 0, 0);
}
