/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:37:45 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/27 15:57:19 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "../libft/libft.h"
# include <pthread.h>
# include <math.h>

# define KEYPRESS 2
# define KEYPRESSMASK (1L << 0)
# define MOTIONNOTIFY 6
# define POINTERMASK (1L<<6)
# define DESTROYNOTIFY 17
# define KEYRELEASEMASK (1L<<1)

typedef struct	s_img
{
	char		*name;
	void		*ptr;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			size_line;
	int			endian;
	double		z;
	double		c[2];
	double		mx;
	double		my;
	int			it;
	int			clr;
}				t_img;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			tr;
	t_img		img;
}				t_data;

void			ft_str_color(char *str, int nl);
int				ft_data_init(t_data *data, char *name);
int				ft_mouse_event(int key, int x, int y, t_data *data);
int				ft_mouse_over(int x, int y, t_data *data);
int				ft_keyboard_event(int button, t_data *data);
void			ft_julia(t_img img);
void			ft_mandelbrot(t_img img);
void			ft_grass(t_img img);
int				ft_sequence(t_img img, double c[2], double z[2], int max);
void			ft_pixel_put(int i, int s, int j[2], t_img img);
int				quit(void);

#endif
