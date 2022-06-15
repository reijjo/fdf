/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:26:40 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/23 10:47:28 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define RED_PX	0xFF0000
# define WHITE_PX 0xFFFFFF
# define GREEN_PX 0xFF00
# define KIVA_GREEN 0x1ABC9C
# define LIGHT_BLUE 0xA0D5FE
# define LILA 0xCF46F0

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		height;
	int		width;
	int		**z_matrix;

	int		color;
	int		zoom;

	int		shift_x;
	int		shift_y;

	float	p_x[3];
	float	p_y[3];
	float	z;
	float	z1;
	float	x_step;
	float	y_step;
	int		max;

	float	x;
	float	y;
	int		fd1;
	int		fd2;
	int		fd3;
	int		key;
}	t_data;

void	read_file(char *file, t_data *data);
void	error_msg(char *str);
void	print_menu(t_data *data);
float	bigger_one(float a, float b);
void	isometric(float *x, float *y, int z);
int		keycode(int key, t_data *data);
void	draw(t_data *data);
void	draw2(t_data *data);
int		colors(int z, int z1, t_data *data);
void	bresenham(float *x, float *y, t_data *data);
void	add_values_x(float x, float x1, t_data *data);
void	add_values_y(float y, float y1, t_data *data);
void	iso_proj(float *x, float *y, t_data *data);
void	zoom_basic(float *x, float *y, t_data *data);
void	move_map(float *x, float *y, t_data *data);
void	select_proj(t_data *data);
int		deal_key1(int key, t_data *data);
int		deal_key2(int key, t_data *data);

#endif
