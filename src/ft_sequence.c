/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:14:28 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 15:31:29 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int		ft_classic_sequence(double c[2], double z[2], int max)
{
	double	t;
	int		i;

	i = 0;
	while (i < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = t;
		i++;
	}
	return (i);
}

static int		ft_cube_sequence(double c[2], double z[2], int max)
{
	double	t;
	int		i;

	i = 0;
	while (i < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] + c[0];
		z[1] = 3 * z[0] * z[0] * z[1] + c[1] - z[1] * z[1] * z[1];
		z[0] = t;
		i++;
	}
	return (i);
}

static int		ft_ship_sequence(double c[2], double z[2], int max)
{
	double	t;
	int		i;

	i = 0;
	while (i < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = fabs(z[0]) * fabs(z[0]) - fabs(z[1]) * fabs(z[1]) + c[0];
		z[1] = 2 * fabs(z[0]) * fabs(z[1]) + c[1];
		z[0] = t;
		i++;
	}
	return (i);
}

static int		ft_cube_ship_sequence(double c[2], double z[2], int max)
{
	double	t;
	int		i;

	i = 0;
	while (i < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = fabs(z[0]) * fabs(z[0]) * fabs(z[0]) - 3 * fabs(z[0])
			* fabs(z[1]) * fabs(z[1]) + c[0];
		z[1] = 3 * fabs(z[0]) * fabs(z[0]) * fabs(z[1])
			+ c[1] - fabs(z[1]) * fabs(z[1]) * fabs(z[1]);
		z[0] = t;
		i++;
	}
	return (i);
}

int				ft_sequence(t_img img, double c[2], double z[2], int max)
{
	if (ft_strequ(img.name, "Julia") || ft_strequ(img.name, "Mandelbrot"))
		return (ft_classic_sequence(c, z, max));
	else if (ft_strequ(img.name, "Jcube") || ft_strequ(img.name, "Mcube"))
		return (ft_cube_sequence(c, z, max));
	else if (ft_strequ(img.name, "Jship") || ft_strequ(img.name, "Mship"))
		return (ft_ship_sequence(c, z, max));
	else if (ft_strequ(img.name, "Jcship") || ft_strequ(img.name, "Mcship"))
		return (ft_cube_ship_sequence(c, z, max));
	return (-1);
}
