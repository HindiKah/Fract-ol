#include "../includes/fractol.h"

int		mouse_move(int x, int y, t_env *e)
{
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y ||
			e->mouse_on_off == 0)
		return (0);
	e->x_2 = x;
	e->y_2 = y;
	if (e->trip)
	{
		e->color_m += 3000;
		if (e->color_m > 0xffffff)
			e->color_m = 0x000000;
	}
	e->f(e);
	return (0);
}

int		mouse_click(int b, int x, int y, t_env *e)
{
	if (b == MOUSE_ZOOM)
	{
		e->x += x / 5;
		e->y += y / 5;
		e->z = e->z * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
	}
	if (b == MOUSE_DEZOOM && e->z > 10)
	{
		e->x -= x / 5;
		e->y -= y / 5;
		e->z = e->z / 1.2;
		e->y = e->y / 1.2;
		e->x = e->x / 1.2;
	}
	e->f(e);
	return (0);
}

void	do_zoom(t_env *e)
{
	e->z = e->z * 1.2;
	e->x = e->x * 1.2;
	e->y = e->y * 1.2;
	e->x += WIN_X / 12;
	e->y += WIN_Y / 12;
}

void	do_dezoom(t_env *e)
{
	if (e->z / 1.2 < 10)
		return ;
	e->z = e->z / 1.2;
	e->x = e->x / 1.2;
	e->y = e->y / 1.2;
	e->x -= WIN_X / 12;
	e->y -= WIN_Y / 12;
}
