/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:18:47 by taitomer          #+#    #+#             */
/*   Updated: 2022/05/22 16:57:52 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_line(char **s, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_strsub(*s, 0, i);
		tmp = ft_strdup(&(*s)[i + 1]);
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
		{
			free(*s);
			*s = NULL;
		}
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (1);
}

static int	ft_output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	return (ft_line(&s[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*s[FD_SIZE];

	if (fd < 0 || line == NULL || fd >= FD_SIZE)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ft_output(s, line, ret, fd));
}
