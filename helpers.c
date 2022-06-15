/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:38:04 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 19:04:32 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_msg(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	print_menu(t_data *data)
{
	char	*menu;

	menu = "EXIT -> 'ESC'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, GREEN_PX, menu);
	menu = "MOVE -> 'ARROWS'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 20, GREEN_PX, menu);
	menu = "flat -> '1'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 35, GREEN_PX, menu);
	menu = "isometric -> '2'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 50, GREEN_PX, menu);
	menu = "zoom -> '+/-'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 65, GREEN_PX, menu);
}

float	bigger_one(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	iso_proj(float *x, float *y, t_data *data)
{
	isometric(&x[0], &y[0], data->z);
	isometric(&x[1], &y[1], data->z1);
}
