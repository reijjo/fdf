/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:33:08 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 14:30:04 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_msg("Shit!");
	if (argc != 2)
		error_msg("One argument thanks!");
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 800, "FDF");
	data->zoom = 20;
	select_proj(data);
	print_menu(data);
	mlx_key_hook(data->win_ptr, keycode, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
