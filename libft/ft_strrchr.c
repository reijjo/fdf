/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:29:51 by taitomer          #+#    #+#             */
/*   Updated: 2021/12/02 21:01:01 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*behind;

	i = 0;
	behind = (char *)s;
	while (s[i] != '\0')
		i++;
	while (s[i] != s[0])
	{
		if (s[i] == (char)c)
			return (behind + i);
		i--;
	}
	if (s[i] == (char)c)
		return (behind + i);
	return (0);
}
