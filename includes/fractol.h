#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_X 600
# define WIN_Y 400
# define COLORS 100
# define ZOOM 15
# define KEY_ZOOM 69
# define KEY_DEZOOM 78
# define EXIT 53
# define MOUSE_ON_OFF 49
# define DEEPER 91
# define DEEPLESS 93
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define RESET 15
# define MOUSE_ZOOM 5
# define MOUSE_DEZOOM 4
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct	s_fractal
{
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	zr;
	long double	zi;
	long double	cr;
	long double	ci;
	long double	tmp;
}				t_fractal;

typedef struct	s_env
{
	void		*mlx_p;
	void		*win;
	void		*img_p;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
	t_fractal	*draw;
	intmax_t	x;
	int			x_2;
	intmax_t	y;
	int			y_2;
	intmax_t	z;
	int			width;
	int			height;
	int			fractal;
	int			color;
	int			color_m;
	int			iter_max;
	int			mouse_on_off;
}				t_env;

int				give_pixel(int x, int y);
void			put_pixel(t_env *e, int x, int y, unsigned int c);
int				count_julia(t_env *e);
int				give_color(t_env *e, int i);
void			fractal_julia(t_env *e);
void			init_julia(t_fractal *draw);
int				mouse_move(int x, int y, t_env *e);
int				mouse_click(int b, int x, int y, t_env *e);
void			do_zoom(t_env *e);
void			do_dezoom(t_env  *e);
int				fractal(t_env *e, int fractal);
int				key_fun(int k, t_env *e);

#endif
