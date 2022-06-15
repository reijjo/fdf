/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:55:33 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/10 17:14:28 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	first;
	size_t	second;

	first = 0;
	while (s1[first] != '\0')
		first++;
	second = 0;
	while (s2[second] != '\0' && second < n)
	{
		s1[first + second] = s2[second];
		second++;
	}
	s1[first + second] = '\0';
	return (s1);
}
