/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:46:35 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 19:03:26 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key1(int key, t_data *data)
{
	if (key == 126)
		data->shift_y = data->shift_y - 10;
	if (key == 125)
		data->shift_y = data->shift_y + 10;
	if (key == 123)
		data->shift_x = data->shift_x - 10;
	if (key == 124)
		data->shift_x = data->shift_x + 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_menu(data);
	draw(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_menu(data);
	return (0);
}

int	deal_key2(int key, t_data *data)
{
	if (key == 126)
		data->shift_y = data->shift_y - 10;
	if (key == 125)
		data->shift_y = data->shift_y + 10;
	if (key == 123)
		data->shift_x = data->shift_x - 10;
	if (key == 124)
		data->shift_x = data->shift_x + 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_menu(data);
	draw2(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_menu(data);
	return (0);
}

void	select_proj(t_data *data)
{
	char	*select;

	select = "Choose projection:";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1000 / 5,
		200, GREEN_PX, select);
	select = "flat -> '1'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1000 / 5,
		220, GREEN_PX, select);
	select = "isometric -> '2'";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1000 / 5,
		240, GREEN_PX, select);
}

int	zoomkey(int key, t_data *data)
{
	if (key == 27 || key == 78)
		data->zoom = data->zoom - 2;
	if (key == 24 || key == 69)
		data->zoom = data->zoom + 2;
	return (0);
}

int	keycode(int key, t_data *data)
{
	deal_key2(key, data);
	zoomkey(key, data);
	if (key == 18)
	{
		draw(data);
		deal_key1(key, data);
	}
	if (key == 19)
	{
		draw2(data);
		deal_key2(key, data);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		error_msg("goodbye!");
	}
	return (0);
}
