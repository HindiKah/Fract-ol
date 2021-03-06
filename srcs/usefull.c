#include "../includes/fractol.h"

int			give_color(t_env *e, int i)
{
	int r;
	int g;
	int b;
	int color;

	if (i == e->iter_max)
		return (e->color_m);
	r = (255 - (i * 4)) * e->color;
	g = (255 - (i * 6)) * e->color;
	b = (255 - (i * 9)) * e->color;
	color = (r << 16) + (g << 8) + b;
	return (color);
}

void		put_pixel(t_env *e, int x, int y, unsigned int c)
{
	int i;

	i = (x * 4) + (y * e->size_l);
	e->data[i] = c;
	e->data[++i] = c >> 8;
	e->data[++i] = c >> 16;
}
