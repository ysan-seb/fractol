/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:55:41 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/12/27 15:56:24 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#define C0 "\e[38;5;196m"
#define C1 "\e[38;5;202m"
#define C2 "\e[38;5;208m"
#define C3 "\e[38;5;214m"
#define C4 "\e[38;5;220m"
#define C5 "\e[38;5;226m"

void	ft_str_color(char *str, int nl)
{
	int			i;
	int			j;
	int			k;
	static char tab[6][14] = {C0, C1, C2, C3, C4, C5};

	i = 0;
	j = ft_strlen(str);
	k = 0;
	j = (j < 6) ? 1 : ft_strlen(str) / 6;
	while (str[i])
	{
		ft_putstr_fd(tab[k], 2);
		write(2, &str[i], 1);
		i++;
		((i % j) == 0) ? k++ : 0;
	}
	if (nl)
		ft_putchar_fd('\n', 2);
	ft_putstr_fd("\e[0m", 2);
}
