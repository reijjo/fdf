/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:27:42 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 11:32:47 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(float *x, float *y, t_data *data)
{
	data->z = data->z_matrix[(int)y[0]][(int)x[0]];
	data->z1 = data->z_matrix[(int)y[1]][(int)x[1]];
	zoom_basic(&x[0], &y[0], data);
	data->color = colors(data->z, data->z1, data);
	move_map(&x[0], &y[0], data);
	data->x_step = x[1] - x[0];
	data->y_step = y[1] - y[0];
	data->max = bigger_one(fabsf(data->x_step), fabsf(data->y_step));
	data->x_step = data->x_step / data->max;
	data->y_step = data->y_step / data->max;
	while ((int)(x[0] - x[1]) || (int)(y[0] - y[1]))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x[0], y[0], data->color);
		x[0] = x[0] + data->x_step;
		y[0] = y[0] + data->y_step;
	}
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				add_values_x(x, x + 1, data);
				add_values_y(y, y, data);
				bresenham(data->p_x, data->p_y, data);
			}
			if (y < data->height - 1)
			{
				add_values_x(x, x, data);
				add_values_y(y, y + 1, data);
				bresenham(data->p_x, data->p_y, data);
			}
			x++;
		}
		y++;
	}
}

void	bresenham2(float *x, float *y, t_data *data)
{
	data->z = data->z_matrix[(int)y[0]][(int)x[0]];
	data->z1 = data->z_matrix[(int)y[1]][(int)x[1]];
	zoom_basic(&x[0], &y[0], data);
	data->color = colors(data->z, data->z1, data);
	iso_proj(&x[0], &y[0], data);
	move_map(&x[0], &y[0], data);
	data->x_step = x[1] - x[0];
	data->y_step = y[1] - y[0];
	data->max = bigger_one(fabsf(data->x_step), fabsf(data->y_step));
	data->x_step = data->x_step / data->max;
	data->y_step = data->y_step / data->max;
	while ((int)(x[0] - x[1]) || (int)(y[0] - y[1]))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x[0], y[0], data->color);
		x[0] = x[0] + data->x_step;
		y[0] = y[0] + data->y_step;
	}
}

void	draw2(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				add_values_x(x, x + 1, data);
				add_values_y(y, y, data);
				bresenham2(data->p_x, data->p_y, data);
			}
			if (y < data->height - 1)
			{
				add_values_x(x, x, data);
				add_values_y(y, y + 1, data);
				bresenham2(data->p_x, data->p_y, data);
			}
			x++;
		}
		y++;
	}
}
