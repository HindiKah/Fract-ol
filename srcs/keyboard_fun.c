#include "../includes/fractol.h"

static void		move(int k, t_env *e)
{
	if (k == DOWN)
		e->y += 100;
	if (k == UP)
		e->y -= 100;
	if (k == RIGHT)
		e->x += 100;
	if (k == LEFT)
		e->x -= 100;
}

static void		zoom(int k, t_env *e)
{
	if (k == KEY_ZOOM)
		do_zoom(e);
	if (k == KEY_DEZOOM)
		do_dezoom(e);
}

static void		reset(int k, t_env *e)
{
	if (k == RESET)
	{
		e->x = 0;
		e->y = 0;
		e->z = 150;
		e->x_2 = WIN_X / 2;
		e->y_2 = WIN_Y / 2;
		e->color_m = 0x000000;
		e->iter_max = 50;
		e->mouse_on_off = 0;
		e->color = 1;
	}
}

int				key_fun(int k, t_env *e)
{
	if (k == DEEPER)
		e->iter_max += 10;
	if (k == DEEPLESS)
		e->iter_max -= 10;
	if (k == MOUSE_ON_OFF)
		e->mouse_on_off = !e->mouse_on_off;
	if (k == EXIT)
	{
		mlx_destroy_window(e->mlx_p, e->win);
		exit(0);
	}
	zoom(k, e);
	move(k, e);
	reset(k, e);
	fractal(e, e->fractal);
	return (0);
}
