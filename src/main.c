/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:10:11 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/20 16:33:56 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int		usage(void)
{
	ft_putstr_fd("Usage : fractol [", 2);
	ft_str_color("fractal name", 0);
	write(2, "]\n", 2);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Julia", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Jcube", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Jship", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Jcship", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Mandelbrot", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Mcube", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Mship", 1);
	ft_putstr_fd("\t\t - ", 2);
	ft_str_color("Mcship", 1);
	return (-1);
}

static int		fractal_exec(char *name, t_data data)
{
	if (ft_strequ(name, "Mandelbrot") || ft_strequ(name, "Mcube")
			|| ft_strequ(name, "Mship") || ft_strequ(name, "Mcship"))
		ft_mandelbrot(data.img);
	else if (ft_strequ(name, "Julia") || ft_strequ(name, "Jcube")
			|| ft_strequ(name, "Jship") || ft_strequ(name, "Jcship"))
		ft_julia(data.img);
	return (0);
}

static int		fractal_name_check(char *str)
{
	if (ft_strequ(str, "Julia") || ft_strequ(str, "Jcube")
			|| ft_strequ(str, "Jship") || ft_strequ(str, "Jcship")
			|| ft_strequ(str, "Mandelbrot") || ft_strequ(str, "Mcube")
			|| ft_strequ(str, "Mship") || ft_strequ(str, "Mcship"))
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && fractal_name_check(argv[1]))
	{
		data.img.name = argv[1];
		if (!(data.mlx = mlx_init()))
			return (-1);
		data.win = mlx_new_window(data.mlx, 1000, 1000, argv[1]);
		ft_data_init(&data, argv[1]);
		fractal_exec(argv[1], data);
		mlx_put_image_to_window(data.mlx, data.win, data.img.ptr, 0, 0);
		mlx_mouse_hook(data.win, ft_mouse_event, &data);
		mlx_hook(data.win, MOTIONNOTIFY, POINTERMASK, ft_mouse_over, &data);
		mlx_hook(data.win, KEYPRESS, KEYPRESSMASK, ft_keyboard_event, &data);
		mlx_hook(data.win, DESTROYNOTIFY, KEYRELEASEMASK, quit, 0);
		mlx_loop(data.mlx);
	}
	else
		return (usage());
	return (0);
}
