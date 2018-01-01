/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:45:27 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 18:10:29 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	ft_is_key(int key)
{
	if (key == 53 || key == 49 || key == 78 || key == 69 || key == 126
			|| key == 125 || key == 124 || key == 123 || key == 116
			|| key == 121)
		return (1);
	return (0);
}

static void	ft_reset(t_data *data)
{
	data->img.c[0] = 0;
	data->img.z = 0.3;
	if (ft_strequ(data->img.name, "Mandelbrot"))
	{
		data->img.z = 0.3;
		data->img.c[0] = -0.65;
	}
	else if (ft_strequ(data->img.name, "Mship"))
	{
		data->img.c[0] = -0.4;
		data->img.c[1] = -0.5;
		return ;
	}
	else if (ft_strequ(data->img.name, "Julia")
			|| ft_strequ(data->img.name, "Jcube")
			|| ft_strequ(data->img.name, "Jship")
			|| ft_strequ(data->img.name, "Jcship"))
		data->img.z = 0.2;
	data->img.c[1] = 0;
}

static void	ft_key_event(int key, t_data *data)
{
	if (key == 53)
		quit();
	else if (key == 49)
		ft_reset(data);
	else if (key == 78 && data->img.it > 3)
		data->img.it -= 1;
	else if (key == 69)
		data->img.it += 1;
	else if (key == 126)
		data->img.c[1] += 0.01 / data->img.z;
	else if (key == 125)
		data->img.c[1] -= 0.01 / data->img.z;
	else if (key == 123)
		data->img.c[0] += 0.01 / data->img.z;
	else if (key == 124)
		data->img.c[0] -= 0.01 / data->img.z;
	else if (key == 116)
		data->img.clr = 0;
	else if (key == 121)
		data->img.clr = 1;
}

int			ft_keyboard_event(int key, t_data *data)
{
	if (ft_is_key(key))
		ft_key_event(key, data);
	else
		return (1);
	if (ft_strequ(data->img.name, "Mandelbrot")
			|| ft_strequ(data->img.name, "Mcube")
			|| ft_strequ(data->img.name, "Mship")
			|| ft_strequ(data->img.name, "Mcship"))
		ft_mandelbrot(data->img);
	else if (ft_strequ(data->img.name, "Julia")
			|| ft_strequ(data->img.name, "Jcube")
			|| ft_strequ(data->img.name, "Jship")
			|| ft_strequ(data->img.name, "Jcship"))
		ft_julia(data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}
