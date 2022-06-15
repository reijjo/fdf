/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:55:55 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 18:37:53 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file, t_data *data)
{
	char	*line;
	int		height;

	data->fd1 = open(file, O_RDONLY);
	if (data->fd1 < 0)
		error_msg("bad filename");
	height = 0;
	while (get_next_line(data->fd1, &line))
	{
		height++;
		free(line);
	}
	close(data->fd1);
	return (height);
}

int	get_width(char *file, t_data *data)
{
	char	*line;
	int		width;

	data->fd2 = open(file, O_RDONLY);
	if (data->fd2 < 0)
		error_msg("bad filename");
	get_next_line(data->fd2, &line);
	width = ft_count_words(line, ' ');
	free(line);
	close(data->fd2);
	return (width);
}

void	fill_map(int *z_line, char *line)
{
	char	**num;
	int		i;

	num = ft_strsplit(line, ' ');
	i = 0;
	while (num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *file, t_data *data)
{
	char	*line;
	int		i;

	data->height = get_height(file, data);
	data->width = get_width(file, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
		error_msg("matrix problems.");
	i = -1;
	while (i < data->height)
		data->z_matrix[++i] = (int *)malloc(sizeof(int) * (data->width + 1));
	if (!data->z_matrix[i])
		error_msg("matrix[i] problems.");
	data->fd3 = open(file, O_RDONLY);
	if (data->fd3 < 0)
		error_msg("Shitty file.");
	i = 0;
	while (get_next_line(data->fd3, &line))
	{
		fill_map(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(data->fd3);
	free(data->z_matrix[i]);
}
