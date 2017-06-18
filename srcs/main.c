#include "../includes/fractol.h"

t_env		*init_env()
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	if (!e)
		return (NULL);
	e->x = 0;
	e->y = 0;
	e->x_2 = WIN_X / 2;
	e->y_2 = WIN_Y / 2;
	e->z = 150;
	e->fractal = 0;
	e->color_m = 0x000000;
	e->color = 1;
	e->mouse_on_off = 1;
	e->iter_max = 150;
	e->mlx_p = mlx_init();
	e->img_p = mlx_new_image(e->mlx_p, WIN_X, WIN_Y);
	e->data = (char*)mlx_get_data_addr(e->img_p,
			&e->bpp, &e->size_l,  &e->endian);
	e->draw = (t_fractal*)malloc(sizeof(t_fractal));
	return (e);
}

int			fractal(t_env *e, int fractal)
{
	if (fractal == 1)
	{
		fractal_julia(e);
		return (1);
	}
	else if (fractal == 2)
	{
		return (1);
	}
	else if (fractal == 3)
	{
		return (1);
	}
	else
		return (0);
}

int			fractal_hook(t_env *e)
{
	fractal(e, e->fractal);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	*e;

	e = init_env();
	if (argc > 2)
		return (0);;
	if (argv[0][0] == 'w')
		return (0);
	e = init_env();
	init_julia(e->draw);
	e->fractal = 1;
	e->win = mlx_new_window(e->mlx_p, WIN_X, WIN_Y, "Fractol");
	mlx_expose_hook(e->win, fractal_hook, e);
	mlx_key_hook(e->win, key_fun, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move, e);
	mlx_mouse_hook(e->win, mouse_click, e);
	fractal(e, e->fractal);
	mlx_loop(e->mlx_p);
	return (0);
}
