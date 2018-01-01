/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:32:10 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 17:34:11 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	ft_color(int i, int s, int a, int b)
{
	unsigned char	color[6];
	int				ret;

	color[0] = (a << 8) >> 24;
	color[1] = (a << 16) >> 24;
	color[2] = (a << 24) >> 24;
	color[3] = (b << 8) >> 24;
	color[4] = (b << 16) >> 24;
	color[5] = (b << 24) >> 24;
	ret = ((color[0] * s / i + color[3] - color[3] * s / i) << 16)
		+ ((color[1] * s / i + color[4] - color[4] * s / i) << 8)
		+ (color[2] * s / i + color[5] - color[5] * s / i);
	return (ret);
}

static void	ft_gradient(int i, int s, int j[2], t_img img)
{
	int clr;

	if (s == i)
		clr = 0;
	else if (s > i / 2)
		clr = ft_color(i / 2, s - i / 2,
				(0xFF << 16) + (0xBF << 8), 0xFF << 16);
	else
		clr = ft_color(i / 2, s, 0xFF << 16, (0xFF << 16) + (0xBF << 8));
	img.addr[j[1] * img.size_line + j[0]
		* img.bpp / 8] = (clr << 24) >> 24;
	img.addr[j[1] * img.size_line + j[0]
		* img.bpp / 8 + 1] = (clr << 16) >> 24;
	img.addr[j[1] * img.size_line + j[0]
		* img.bpp / 8 + 2] = (clr << 8) >> 24;
}

static void	ft_classic(int i, int s, int j[2], t_img img)
{
	int clr;

	clr = 6;
	if (s == i)
		clr = 0;
	img.addr[j[1] * img.size_line + j[0]
		* img.bpp / 8] = s / 3 * clr * 0.42;
	img.addr[j[1] * img.size_line + j[0]
		* img.bpp / 8 + 1] = s / 3 * clr * 4.2;
	img.addr[j[1] * img.size_line + j[0]
		* img.bpp / 8 + 2] = s / 3 * clr * 42;
}

void		ft_pixel_put(int i, int s, int j[2], t_img img)
{
	if (img.clr)
		ft_gradient(i, s, j, img);
	else
		ft_classic(i, s, j, img);
}
