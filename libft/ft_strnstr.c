/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:58:41 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/17 15:15:00 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	char	*all;
	char	*find;

	i = 0;
	all = (char *)haystack;
	find = (char *)needle;
	if (find[0] == '\0')
		return (all);
	while (all[i] != '\0' && i < len)
	{
		if (all[i] == find[0])
		{
			k = 0;
			while (all[i + k] == find[k] && i + k < len)
			{
				if (find[k + 1] == '\0')
					return (all + i);
				k++;
			}
		}
		i++;
	}
	return (NULL);
}
