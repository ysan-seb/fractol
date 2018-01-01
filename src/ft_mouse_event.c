/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:40:14 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 15:29:16 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_center_new(t_data *data, int x, int y)
{
	data->img.c[0] = x / (data->img.w * data->img.z)
		- 0.5 / data->img.z + data->img.c[0];
	data->img.c[1] = y / (data->img.h * data->img.z)
		- 0.5 / data->img.z + data->img.c[1];
}

static void	ft_transform(t_data *data)
{
	if (data->tr == 0)
		data->tr = 1;
	else
		data->tr = 0;
}

static void	ft_zoom_more(t_data *data, int x, int y)
{
	data->img.c[0] = (data->img.c[0] + x / (data->img.w * data->img.z)
			- 0.5 / data->img.z + data->img.c[0]) / 2;
	data->img.c[1] = (data->img.c[1] + y / (data->img.h * data->img.z)
			- 0.5 / data->img.z + data->img.c[1]) / 2;
	data->img.z *= 2;
}

static void	ft_zoom_less(t_data *data, int x, int y)
{
	data->img.c[0] = 2 * data->img.c[0] - (x / (data->img.w * data->img.z)
			- 0.5 / data->img.z + data->img.c[0]);
	data->img.c[1] = 2 * data->img.c[1] - (y / (data->img.h * data->img.z)
			- 0.5 / data->img.z + data->img.c[1]);
	data->img.z /= 2;
}

int			ft_mouse_event(int key, int x, int y, t_data *d)
{
	if (y < 0)
		return (1);
	if (key == 1)
		ft_center_new(d, x, y);
	if (key == 2)
		ft_transform(d);
	if (key == 4)
		ft_zoom_more(d, x, y);
	else if (key == 5)
		ft_zoom_less(d, x, y);
	if (ft_strequ(d->img.name, "Mandelbrot") || ft_strequ(d->img.name, "Mcube")
			|| ft_strequ(d->img.name, "Mship")
			|| ft_strequ(d->img.name, "Mcship"))
		ft_mandelbrot(d->img);
	else if (ft_strequ(d->img.name, "Julia") || ft_strequ(d->img.name, "Jcube")
			|| ft_strequ(d->img.name, "Jship")
			|| ft_strequ(d->img.name, "Jcship"))
		ft_julia(d->img);
	mlx_put_image_to_window(d->mlx, d->win, d->img.ptr, 0, 0);
	return (0);
}
