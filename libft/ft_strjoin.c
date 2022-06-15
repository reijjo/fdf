/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:36:44 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/27 17:47:48 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		k;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		fresh[i + k] = s2[k];
		k++;
	}
	fresh[i + k] = '\0';
	return (fresh);
}
