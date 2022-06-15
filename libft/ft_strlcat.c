/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:28:39 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/19 12:09:11 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	dest;
	size_t	source;

	dest = ft_strlen(dst);
	source = ft_strlen(src);
	if (dstsize < dest)
		return (source + dstsize);
	i = 0;
	while (dst[i] != '\0')
		i++;
	k = 0;
	while (i + 1 < (dstsize) && src[k] != '\0')
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dest + source);
}
