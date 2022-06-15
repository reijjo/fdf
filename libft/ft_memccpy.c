/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:05:39 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/17 14:24:41 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*original;
	unsigned char	*copy;
	unsigned char	found;
	size_t			i;

	original = (unsigned char *)src;
	copy = (unsigned char *)dst;
	found = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (original[i] == found)
		{
			copy[i] = original[i];
			return (dst + i + 1);
		}
		copy[i] = original[i];
		i++;
	}
	return (NULL);
}
