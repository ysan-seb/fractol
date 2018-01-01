/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:49:10 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/21 16:02:42 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	ft_m_init(t_data *data, char *name)
{
	data->img.z = 0.3;
	if (ft_strequ(name, "Mship"))
	{
		data->img.c[0] = -0.4;
		data->img.c[1] = -0.5;
		data->img.it = 50;
		return (1);
	}
	data->img.c[0] = (ft_strequ(name, "Mandelbrot")) ? -0.65 : 0;
	return (0);
}

static int	ft_image_init(t_data *data)
{
	if (!(data->img.ptr = mlx_new_image(data->mlx, data->img.w, data->img.h)))
		return (-1);
	if (!(data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
					&data->img.size_line, &data->img.endian)))
		return (-1);
	return (0);
}

int			ft_data_init(t_data *data, char *name)
{
	data->tr = 0;
	data->img.clr = 6;
	data->img.w = 1000;
	data->img.h = 1000;
	if ((ft_image_init(data)) == -1)
		return (-1);
	if (ft_strequ(name, "Mandelbrot") || ft_strequ(name, "Mcube")
			|| ft_strequ(name, "Mship") || ft_strequ(name, "Mcship"))
	{
		if (ft_m_init(data, name))
			return (0);
	}
	else if (ft_strequ(name, "Julia") || ft_strequ(name, "Jcube")
			|| ft_strequ(name, "Jship") || ft_strequ(name, "Jcship"))
	{
		data->img.z = 0.2;
		data->img.c[0] = 0;
	}
	data->img.it = 50;
	data->img.c[1] = 0;
	return (0);
}
