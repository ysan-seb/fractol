/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_over.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:43:30 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 16:12:27 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_mouse_over(int x, int y, t_data *data)
{
	if (ft_strequ(data->img.name, "Julia") || ft_strequ(data->img.name, "Jcube")
			|| ft_strequ(data->img.name, "Jship")
			|| ft_strequ(data->img.name, "Jcship"))
	{
		if (data->tr == 1)
			return (-1);
		data->img.mx = x / (data->img.w / 2.0) - 1;
		data->img.my = y / (data->img.h / 2.0) - 1;
		ft_julia(data->img);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	}
	return (0);
}
