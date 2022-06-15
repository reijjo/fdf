/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:42:09 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/07 16:03:19 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		k;
	char	*find;
	char	*all;

	find = (char *)needle;
	all = (char *)haystack;
	i = 0;
	if (find[0] == '\0')
		return (all);
	while (all[i] != '\0')
	{
		k = 0;
		while (all[i + k] == find[k])
		{
			if (find[k + 1] == '\0')
				return (all + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
