/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:55:23 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 18:14:48 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	*ft_mandelbrot_tone(void *ig)
{
	t_img	*img;
	double	c[2];
	double	z[2];
	int		j[2];
	int		i;

	img = (t_img*)ig;
	j[0] = 0;
	i = img->it + img->z * 0.2;
	while (j[0] < img->w)
	{
		j[1] = 0;
		while (j[1] < img->h)
		{
			ft_memset(z, 0, sizeof(double) * 2);
			c[0] = j[0] / (img->w * img->z) - 0.5 / img->z + img->c[0];
			c[1] = j[1] / (img->h * img->z) - 0.5 / img->z + img->c[1];
			ft_pixel_put(i, ft_sequence(*img, c, z, i), j, *img);
			j[1] += 4;
		}
		j[0]++;
	}
	return (NULL);
}

static void	*ft_mandelbrot_ttwo(void *ig)
{
	t_img	*img;
	double	c[2];
	double	z[2];
	int		j[2];
	int		i;

	img = (t_img*)ig;
	j[0] = 0;
	i = img->it + img->z * 0.2;
	while (j[0] < img->w)
	{
		j[1] = 1;
		while (j[1] < img->h)
		{
			ft_memset(z, 0, sizeof(double) * 2);
			c[0] = j[0] / (img->w * img->z) - 0.5 / img->z + img->c[0];
			c[1] = j[1] / (img->h * img->z) - 0.5 / img->z + img->c[1];
			ft_pixel_put(i, ft_sequence(*img, c, z, i), j, *img);
			j[1] += 4;
		}
		j[0]++;
	}
	return (NULL);
}

static void	*ft_mandelbrot_tthree(void *ig)
{
	t_img	*img;
	double	c[2];
	double	z[2];
	int		j[2];
	int		i;

	img = (t_img*)ig;
	j[0] = 0;
	i = img->it + img->z * 0.2;
	while (j[0] < img->w)
	{
		j[1] = 2;
		while (j[1] < img->h)
		{
			ft_memset(z, 0, sizeof(double) * 2);
			c[0] = j[0] / (img->w * img->z) - 0.5 / img->z + img->c[0];
			c[1] = j[1] / (img->h * img->z) - 0.5 / img->z + img->c[1];
			ft_pixel_put(i, ft_sequence(*img, c, z, i), j, *img);
			j[1] += 4;
		}
		j[0]++;
	}
	return (NULL);
}

static void	*ft_mandelbrot_tfour(void *ig)
{
	t_img	*img;
	double	c[2];
	double	z[2];
	int		j[2];
	int		i;

	img = (t_img*)ig;
	j[0] = 0;
	i = img->it + img->z * 0.2;
	while (j[0] < img->w)
	{
		j[1] = 3;
		while (j[1] < img->h)
		{
			ft_memset(z, 0, sizeof(double) * 2);
			c[0] = j[0] / (img->w * img->z) - 0.5 / img->z + img->c[0];
			c[1] = j[1] / (img->h * img->z) - 0.5 / img->z + img->c[1];
			ft_pixel_put(i, ft_sequence(*img, c, z, i), j, *img);
			j[1] += 4;
		}
		j[0]++;
	}
	return (NULL);
}

void		ft_mandelbrot(t_img img)
{
	int			i;
	pthread_t	thread[4];

	if ((pthread_create(&thread[0], NULL, ft_mandelbrot_tone, &img)))
		return ;
	if ((pthread_create(&thread[1], NULL, ft_mandelbrot_ttwo, &img)))
		return ;
	if ((pthread_create(&thread[2], NULL, ft_mandelbrot_tthree, &img)))
		return ;
	if ((pthread_create(&thread[3], NULL, ft_mandelbrot_tfour, &img)))
		return ;
	i = 0;
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	return ;
}
