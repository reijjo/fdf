/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:30:09 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/18 16:28:23 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*find;
	char	found;

	i = 0;
	find = (char *)s;
	found = (char)c;
	while (s[i] != '\0')
	{
		if (find[i] == found)
			return (find + i);
		i++;
	}
	if (find[i] == found)
		return (find + i);
	return (NULL);
}
