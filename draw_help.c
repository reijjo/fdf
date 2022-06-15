/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:12:17 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/23 11:06:35 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colors(int z, int z1, t_data *data)
{
	if (z || z1)
		data->color = RED_PX;
	else
		data->color = KIVA_GREEN;
	return (data->color);
}

void	add_values_x(float x, float x1, t_data *data)
{
	data->p_x[0] = x;
	data->p_x[1] = x1;
}

void	add_values_y(float y, float y1, t_data *data)
{
	data->p_y[0] = y;
	data->p_y[1] = y1;
}

void	zoom_basic(float *x, float *y, t_data *data)
{
	x[0] = x[0] * data->zoom;
	y[0] = y[0] * data->zoom;
	x[1] = x[1] * data->zoom;
	y[1] = y[1] * data->zoom;
}

void	move_map(float *x, float *y, t_data *data)
{
	x[0] = x[0] + data->shift_x;
	y[0] = y[0] + data->shift_y;
	x[1] = x[1] + data->shift_x;
	y[1] = y[1] + data->shift_y;
}
